/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/14 10:00:04 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/**
 * Deprecated, It is the old v4 algo but I is not good
 */
void ft_auto_sortV5(t_stack_master *stack_master)
{
	t_perfect_stack perfect_stack;
	int top;

	perfect_stack = ft_get_perfect_stack(stack_master);
	while (!(ft_is_correct(stack_master)))
	{
		int bad_index;
		/*if ((bad_index = is_bad_index_only(stack_master)) > -1) {
			jump_to_index(stack_master, bad_index, 0);
		}
		else */
		if (ft_is_upside_down(stack_master->b) && (ft_stack_is_empty(stack_master->a) /*|| ft_is_correct_order(stack_master->a)*/))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				ft_sort_and_print(stack_master, "pa");
				top--;
			}
			break;
		}
		else if (ft_stack_is_empty(stack_master->a) && (bad_index = is_bad_index_only_b(stack_master)) > -1)
		{
			jump_to_index(stack_master, bad_index, 1);
		}
		else if (stack_master->b->top >= 1)
		{
			int index_b = ft_get_perfect_index_b(stack_master->a->array[stack_master->a->top], perfect_stack.perfect_array_b, perfect_stack.size_b, stack_master->b);
			if (index_b == -1)
				ft_error("Can't find perfect index on B");
			jump_to_index(stack_master, index_b, 1);
			ft_sort_and_print(stack_master, "pb");
		}
		else if (stack_master->b->top < 2)
		{
			ft_sort_and_print(stack_master, "pb");
		}
		else
			ft_error("Can't sort");
		ft_free_perfect_stack(perfect_stack);
		perfect_stack = ft_get_perfect_stack(stack_master);
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
		{
			ft_error("Stack B is not sorted");
		}
	}
	ft_free_perfect_stack(perfect_stack);
}
