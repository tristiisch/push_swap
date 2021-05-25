/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_to_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:37:07 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:37:46 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	index_to_times(int index, int top)
{
	int		times;

	times = top - index;
	if (times <= (top + 1) / 2)
		return (times);
	else
		return (index + 1);
}

void	jump_to_index_both3(t_stack_master *stack_master, int times_a,
		int times_b)
{
	if (times_b < times_a)
	{
		rr_or_rrr(stack_master, -times_a, 1);
		rra_or_rrb(stack_master, -times_b - -times_a, 1);
	}
	else if (times_a == times_b)
		rr_or_rrr(stack_master, -times_a, 1);
	else
	{
		rr_or_rrr(stack_master, -times_b, 1);
		rra_or_rrb(stack_master, -times_a - -times_b, 0);
	}
}

int	jump_to_index_both2(t_stack_master *stack_master, int times_a,
		int times_b)
{
	if (times_b > 0 && times_a > 0)
	{
		if (times_b > times_a)
		{
			rr_or_rrr(stack_master, times_a, 0);
			ra_or_rb(stack_master, times_b - times_a, 1);
		}
		else if (times_a == times_b)
			rr_or_rrr(stack_master, times_a, 0);
		else
		{
			rr_or_rrr(stack_master, times_b, 0);
			ra_or_rb(stack_master, times_a - times_b, 0);
		}
	}
	else if (times_b < 0 && times_a < 0)
		jump_to_index_both3(stack_master, times_a, times_b);
	else
		return (1);
	return (0);
}

void	jump_to_index_both(t_stack_master *stack_master, int index_a,
		int index_b)
{
	int		top;
	int		times_a;
	int		times_b;

	top = stack_master->a->top;
	times_a = top - index_a;
	if (times_a > (top + 1) / 2)
		times_a = -(index_a + 1);
	top = stack_master->b->top;
	times_b = top - index_b;
	if (times_b > (top + 1) / 2)
		times_b = -(index_b + 1);
	if (jump_to_index_both2(stack_master, times_a, times_b) == 1)
	{
		if (index_a != stack_master->a->top)
			jump_to_index(stack_master, index_a, 0);
		if (index_b != stack_master->b->top)
			jump_to_index(stack_master, index_b, 1);
	}
}
