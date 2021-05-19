/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/19 10:07:26 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_auto_sortV5_2(t_stack_master *stack_master, int bad_index_a)
{
	int	bad_index_b;

	bad_index_b = is_bad_index_only_b(stack_master);
	if (ft_stack_is_empty(stack_master->a) && bad_index_b > -1)
		jump_to_index(stack_master, bad_index_b, 1);
	else if (bad_index_a > -1)
	{
		ft_perfect_shot_a(stack_master,
			stack_master->a->array[*get_index_of_smallest(
				stack_master->a, NULL)],
			stack_master->a->array[*get_index_of_biggest(
				stack_master->a, NULL)]);
	}
	else if (stack_master->b->top > 0)
	{
		ft_perfect_shot_b(stack_master,
			stack_master->b->array[*get_index_of_smallest(
				stack_master->b, NULL)],
			stack_master->b->array[*get_index_of_biggest(
				stack_master->b, NULL)]);
	}
	else if (stack_master->b->top < 2)
		ft_sort_and_print(stack_master, "pb");
	else
		ft_error("Can't sort with algoV5");
}

void	ft_auto_sortV5(t_stack_master *stack_master)
{
	int	top;
	int	bad_index_a;

	while (!(ft_is_correct(stack_master)))
	{
		bad_index_a = is_bad_index_only(stack_master);
		if (ft_stack_is_empty(stack_master->b) && bad_index_a > -1)
			jump_to_index(stack_master, bad_index_a, 0);
		else if (ft_stack_is_empty(stack_master->b)
			&& ft_can_be_revert(stack_master->a))
			ft_sort_and_print(stack_master, "sa");
		else if (ft_stack_is_empty(stack_master->a)
			&& ft_is_upside_down(stack_master->b))
		{
			top = stack_master->b->top;
			while (top-- >= 0)
				ft_sort_and_print(stack_master, "pa");
			break ;
		}
		else
			ft_auto_sortV5_2(stack_master, bad_index_a);
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
			ft_error("Stack B is not sorted");
	}
}
