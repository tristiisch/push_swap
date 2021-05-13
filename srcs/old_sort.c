/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:51:51 by tglory            #+#    #+#             */
/*   Updated: 2021/04/19 17:51:51 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	jump_to_index(t_stack_master *stack_master, int index, int a_or_b)
{
	int		top;
	int		times;
	t_stack	*stack;

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
				ft_sort_and_print(stack_master, "ra");
			else
				ft_sort_and_print(stack_master, "rb");
			times--;
		}
	}
	else
	{
		times = index + 1;
		while (times > 0)
		{
			if (a_or_b == 0)
				ft_sort_and_print(stack_master, "rra");
			else
				ft_sort_and_print(stack_master, "rrb");
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
		ft_sort(stack_master, "pb");
		top--;
	}
	index = 0;
	top = stack_master->b->top;
	while (index <= top)
	{
		ft_sort(stack_master, "pa");
		index++;
	}
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
