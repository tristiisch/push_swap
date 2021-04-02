/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/04/02 04:27:15 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	jump_to_index(t_stack_master *stack_master, int index, int a_or_b)
{
	int top;
	int times;
	t_stack *stack;

	if (a_or_b == 0)
		stack = stack_master->a;
	else if (a_or_b == 1)
		stack = stack_master->b;
	else
	{
		printf("WARN > a_or_b bad parameter `bool`. jump_to_index cancelled\n");
		return ;
	}
	top = stack->top;
	times = top - index;
	if (times <= (top + 1) / 2)
	{
		while (times > 0)
		{
			if (a_or_b == 0)
				sort(stack_master, "ra");
			else
				sort(stack_master, "rb");
			times--;
		}
	} else {
		times = index + 1;
		while (times > 0)
		{
			if (a_or_b == 0)
				sort(stack_master, "rra");
			else
				sort(stack_master, "rrb");
			times--;
		}
	}
	//printf("index %d length %d times %d\n", index, length, times);
	//while (times >= 0)
	//{
	//	ft_rotate(stack);// TODO Change to sort(stack_master, "r#");
	//	printf("r#\n");
		//printf("rotate %d ", times);
		//ft_print_stack(stack);
	//	times--;
//	}
}

/**
 * return -1 if the index cannot be retrive with upper.
 */
int	get_index_of_biggest(t_stack *stack, int under)
{
	int index;
	int saved_index;
	int i;

	index = stack->top;
	//printf("test index %d\n", index);
	i = 0; // TODO remove this to support sorting 0
	saved_index = -1;
	while (index >= 0)
	{
		if ((under == -1 || stack->array[index] < under)
			&& (i == 0 || i < stack->array[index]))
		{
			i = stack->array[index];
			saved_index = index;
		}
		index--;
	}
	//printf("big index is %d = %d\n", saved_index, i);
	return (saved_index);
}

int	get_index_of_smallest(t_stack *stack, int upper)
{
	int index;
	int saved_index;
	int i;

	index = stack->top;
	//printf("test index %d\n", index);
	i = 0; // TODO remove this to support sorting 0
	while (index >= 0)
	{
		if ((upper == -1 || stack->array[index] > upper)
			&& (i == 0 || i > stack->array[index]))
		{
			i = stack->array[index];
			saved_index = index;
		}
		index--;
	}
	//printf("small index is %d = %d\n", saved_index, i);
	return (saved_index);
}

void	sort_by_biggest(t_stack_master *stack_master, int upper)
{
	int top;
	int last_index;
	int index;

	last_index = -1;
	top = (stack_master->a)->top;
	while (top >= 0)
	{
		index = get_index_of_smallest(stack_master->a, upper);
		if (index == -1)
		{
			printf("WARN\nget_index_of_biggest cannot retrive the biggest one. Index = %d\n", index);
			break;
		}
		else if (last_index == index)
		{
			printf("WARN\nsort_by_biggest is identical to the one above. Index = %d\n", index);
			break;
		}
		upper = stack_master->a->array[index];
		last_index = index;
		jump_to_index(stack_master, index, 0);
		sort(stack_master, "pb");
		top--;
	}
	index = 0;
	top = stack_master->b->top;
	while (index <= top)
	{
		sort(stack_master, "pa");
		index++;
	}
}

int**	get_perfect_order(t_stack_master *stack_master, int a_or_b)
{
	int top;
	int last_index;
	int index;
	int last_number;
	int i;
	int **array;
	t_stack *stack;

	if (a_or_b == 0)
		stack = stack_master->a;
	else if (a_or_b == 1)
		stack = stack_master->b;
	else
	{
		printf("WARN > a_or_b bad parameter `bool`. get_perfect_order cancelled\n");
		return NULL;
	}
	last_index = -1;
	top = stack->top;
	last_number = -1;
	i = 0;
	if (top >= 0)
		array = malloc((top + 1) * sizeof(*array));
	else
		array = NULL;
	while (i <= top)
	{
		index = get_index_of_biggest(stack, last_number);
		if (index == -1 || last_index == index)
			break;
		last_index = index;
		last_number = stack->array[index];
		array[i] = malloc(2 * sizeof(int));
		//printf("i = %d, %d-%d\n", i, index, last_number);
		array[i][0] = index;
		array[i][1] = last_number;
		i++;
	}
	//ft_print_int_double_array(array, top + 1);
	return (array);
}

int	can_be_revert(t_stack *stack, int **perfect_array)
{
	int	i;
	int	one;
	int	one_index;
	int	two;
	int	two_index;

	if (stack->top <= 0)
		return (0);
	i = 0;
	one = stack->array[stack->top];
	two = stack->array[stack->top - 1];
	if (one < two)
		return (0);
	one_index = -1;
	two_index = -1;
	while (i <= stack->top && (one_index == -1 || two_index == -1))
	{
		//printf("DEBUG2 %d/%d - %d'%d \n", perfect_array[i][1], one, perfect_array[i][1], two);
		if (one_index == -1 && perfect_array[i][1] == one)
			one_index = i;
		else if (two_index == -1 && perfect_array[i][1] == two)
			two_index = i; 
		i++;
	}
	//ft_print_int_double_array(perfect_array, stack->top + 1);
	//printf("DEBUG %d/%d - %d'%d \n", one_index, two_index, stack->array[stack->top], stack->array[stack->top - 1]);
	if (one_index == -1 || two_index == -1)
		return (0);
	else if (one_index + 1 == two_index)
		return (1);
	return (0);
}


void	test_sort(t_stack_master *stack_master)
{
	int	**perfect_array_a;
	int	**perfect_array_b;
	int	top;
	int	i;

	perfect_array_a = get_perfect_order(stack_master, 0);
	perfect_array_b = get_perfect_order(stack_master, 1);
	i = 0;
	while (!(is_correct(stack_master)) && i < 25)
	{
		//if (perfect_array_a != NULL && stack_master->a->top > 0 && perfect_array_a[stack_master->a->top][0] + 1 == perfect_array_a[stack_master->a->top - 1][0]
		//else if (perfect_array_b != NULL && stack_master->b->top > 0 && perfect_array_b[stack_master->b->top][0] - 1 == perfect_array_b[stack_master->b->top - 1][0])
		//	sort(stack_master, "sb");
		if (is_updside_down(stack_master->b) && (ft_stack_is_empty(stack_master->a) || is_correct_order(stack_master->a)))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				sort(stack_master, "pa");
				top--;
			}
			break;
		}
		else if (get_index_of_smallest(stack_master->a, -1) == stack_master->a->top)
		{
			sort(stack_master, "pb");
		}
		else if (can_be_revert(stack_master->a, perfect_array_a))
			sort(stack_master, "sa");
		else
		{
			if (get_index_of_smallest(stack_master->a, -1) > stack_master->a->top / 2)
				sort(stack_master, "ra");
			else
				sort(stack_master, "rra");
		}
		perfect_array_a = get_perfect_order(stack_master, 0);
		perfect_array_b = get_perfect_order(stack_master, 1);
		i++;
	}
	// TODO free perfect_array_a && perfect_array_b
}


/*
void	check_sort(t_stack_master *stack_master)
{
	int index;

	index = (stack_master->a).length - 1;
	if ((stack_master->a).array[index] > (stack_master->a).array[index - 1])
		sort(stack_master, "sa");
	while ((stack_master->a).array[index] < (stack_master->a).array[index - 1])
	{
		sort(stack_master, "pb");
	}
	if ((stack_master->a).array[0] < (stack_master->a).array[index - 1])
	{
		
	}
}
*/
void	sort(t_stack_master *stack_master, char *operator)
{
	if (ft_strncmp(operator, "rra", 3) == 0)
		ft_reverse_rotate(stack_master->a);
	else if (ft_strncmp(operator, "rrb", 3) == 0)
		ft_reverse_rotate(stack_master->b);
	else if (ft_strncmp(operator, "rrr", 3) == 0)
	{
		ft_reverse_rotate(stack_master->a);
		ft_reverse_rotate(stack_master->b);
		stack_master->instruction++;
	}
	else if (ft_strncmp(operator, "sa", 2) == 0)
		ft_swap(stack_master->a);
	else if (ft_strncmp(operator, "sb", 2) == 0)
		ft_swap(stack_master->b);
	else if (ft_strncmp(operator, "ss", 2) == 0)
	{
		ft_swap(stack_master->a);
		ft_swap(stack_master->b);
		stack_master->instruction++;
	}
	else if (ft_strncmp(operator, "pa", 2) == 0)
		ft_push(stack_master, 0);
	else if (ft_strncmp(operator, "pb", 2) == 0)
		ft_push(stack_master, 1);
	else if (ft_strncmp(operator, "ra", 2) == 0)
		ft_rotate(stack_master->a);
	else if (ft_strncmp(operator, "rb", 2) == 0)
		ft_rotate(stack_master->b);
	else if (ft_strncmp(operator, "rr", 2) == 0)
	{
		ft_rotate(stack_master->a);
		ft_rotate(stack_master->b);
		stack_master->instruction++;
	}
	printf("%s\n", operator);
	stack_master->instruction++;
	ft_print_master_stack(stack_master);
}
