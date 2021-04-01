/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/04/02 01:39:25 by tglory           ###   ########lyon.fr   */
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
			&& (i == 0 || i < stack->array[index]))
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

int**	get_perfect_order(t_stack *stack)
{
	int top;
	int last_index;
	int index;
	int last_number;
	int i;
	int **array;

	last_index = -1;
	top = stack->top;
	last_number = -1;
	i = 0;
	array = malloc(top + 1 * 2 * sizeof(int));
	while (top >= 0)
	{
		index = get_index_of_biggest(stack, last_number);
		if (index == -1 || last_index == index)
			break;
		last_index = index;
		last_number = stack->array[index];
		array[i] = malloc(2 * sizeof(int));
		printf("i = %d, %d-%d\n", i, index, last_number);
		array[i][0] = index;
		array[i][1] = last_number;
		i++;
		top--;
	}
	ft_print_int_double_array(array, stack->top + 1);
	return (array);
}

void	test_sort(t_stack_master *stack_master)
{
	int	**perfect_array;
	int	i;
	int top;
	int last_b;

	perfect_array = get_perfect_order(stack_master->a);
	last_b = perfect_array[0][1];
	i = 0;
	top = stack_master->a->top;
	while (!(is_correct(stack_master)) && i < 50)
	{
		printf("DEBUG > %d-%d(%d)\n", stack_master->a->array[stack_master->a->top], last_b, perfect_array[0][1]);
		if (perfect_array[top][0] + 1 == perfect_array[top - 1][0])
			sort(stack_master, "sa");
		else if (stack_master->a->array[stack_master->a->top] == last_b)
		{
			last_b = stack_master->a->array[stack_master->a->top];
			sort(stack_master, "pb");
		}
		else
			sort(stack_master, "ra");
		i++;
		perfect_array = get_perfect_order(stack_master->a);
	}
	i = 0;
	while (i < stack_master->b->top)
	{
		sort(stack_master, "pa");
		i++;
	}
	i = 0;
	while (i > 0)
		free(perfect_array[i--]);
	free(perfect_array);
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
