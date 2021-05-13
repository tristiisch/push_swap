/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 17:51:51 by tglory            #+#    #+#             */
/*   Updated: 2021/05/13 17:54:22 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_by_biggest(t_stack_master *stack_master, int upper)
{
	int	top;
	int	last_index;
	int	index;

	last_index = -1;
	top = (stack_master->a)->top;
	while (top >= 0)
	{
		index = get_index_of_smallest(stack_master->a, upper);
		if (index == -1)
		{
			printf("WARN\nget_index_of_biggest cannot retrive the biggest one." \
					" Index = %d\n", index);
			break ;
		}
		else if (last_index == index)
		{
			printf("WARN\nsort_by_biggest is identical to the one above." \
					" Index = %d\n", index);
			break ;
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
	int	index;
	int	saved_index;
	int	i;

	index = stack->top;
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
	return (saved_index);
}
