/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_to_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:37:07 by ksam              #+#    #+#             */
/*   Updated: 2021/05/19 08:22:17 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra_or_rb(t_stack_master *stack_master, int times, int a_or_b)
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

void	rra_or_rrb(t_stack_master *stack_master, int times, int a_or_b)
{
	while (times > 0)
	{
		if (a_or_b == 0)
			ft_sort_and_print(stack_master, "rra");
		else
			ft_sort_and_print(stack_master, "rrb");
		times--;
	}
}

void	rr_or_rrr(t_stack_master *stack_master, int times, int rr_or_rrr)
{
	while (times > 0)
	{
		if (rr_or_rrr == 0)
			ft_sort_and_print(stack_master, "rr");
		else
			ft_sort_and_print(stack_master, "rrr");
		times--;
	}
}

int	index_to_times(int index, int top)
{
	int		times;

	times = top - index;
	if (times <= (top + 1) / 2)
		return (times);
	else
		return (index + 1);
}

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
		ra_or_rb(stack_master, times, a_or_b);
	else
		rra_or_rrb(stack_master, index + 1, a_or_b);
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
	else
	{
		if (index_a != stack_master->a->top)
			jump_to_index(stack_master, index_a, 0);
		if (index_b != stack_master->b->top)
			jump_to_index(stack_master, index_b, 1);
	}
}
