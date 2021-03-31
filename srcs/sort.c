/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 03:58:39 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	jump_to_index(t_stack *stack, int index)
{
	int top;
	int times;

	top = stack->top;
	times = top - index;
	if (times <= (top + 1) / 2)
	{
		while (times > 0)
		{
			ft_rotate(stack);// TODO Change to sort(stack_master, "r#");
			printf("r#\n");
			times--;
		}
	} else {
		times = index + 1;
		while (times > 0)
		{
			ft_reverse_rotate(stack);// TODO Change to sort(stack_master, "r#");
			printf("rr#\n");
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

int	get_index_of_bigest(t_stack *stack)
{
	int index;
	int saved_index;
	int i;

	index = stack->top;
	//printf("test index %d\n", index);
	i = 0; // TODO remove this to support sorting 0
	while (index >= 0)
	{
		if (i == 0 || i < stack->array[index])
		{
			i = stack->array[index];
			saved_index = index;
		}
		index--;
	}
	//printf("big index is %d = %d\n", saved_index, i);
	return (saved_index);
}

int	get_index_of_smallest(t_stack *stack)
{
	int index;
	int saved_index;
	int i;

	index = stack->top;
	//printf("test index %d\n", index);
	i = 0; // TODO remove this to support sorting 0
	while (index >= 0)
	{
		if (i == 0 || i > stack->array[index])
		{
			i = stack->array[index];
			saved_index = index;
		}
		index--;
	}
	//printf("small index is %d = %d\n", saved_index, i);
	return (saved_index);
}

void	test_sort(t_stack_master *stack_master)
{
	int top;
	int last_index;
	int index;

	last_index = -1;
	top = (stack_master->a)->top;
	while (top >= 0)
	{
		index = get_index_of_bigest(stack_master->a);
		if (last_index == index)
			break;
		jump_to_index(stack_master->a, index);
		sort(stack_master, "pb");
		top--;
	}
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
