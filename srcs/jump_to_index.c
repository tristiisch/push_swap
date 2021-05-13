/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jump_to_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:37:07 by ksam              #+#    #+#             */
/*   Updated: 2021/05/13 17:49:30 by ksam             ###   ########lyon.fr   */
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

void	rra_or_rrb(t_stack_master *stack_master, int times, int a_or_b, \
					int index)
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
		rra_or_rrb(stack_master, times, a_or_b, index);
}
