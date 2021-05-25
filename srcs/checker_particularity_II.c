/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_particularity_II.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:54:12 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:35:07 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_bad_index_only_a(t_stack_master *stack_master)
{
	int	*start_index;
	int	i;
	int	i1;
	int	i2;

	if (ft_stack_is_empty(stack_master->a))
		return (-1);
	i = -1;
	start_index = get_index_of_biggest(stack_master->a, NULL);
	while (++i < stack_master->a->top)
	{
		if (i + *start_index > stack_master->a->top)
			i1 = i + *start_index - stack_master->a->top - 1;
		else
			i1 = i + *start_index;
		if (i + *start_index + 1 > stack_master->a->top)
			i2 = i + *start_index - stack_master->a->top;
		else
			i2 = i + *start_index + 1;
		if (stack_master->a->array[i1] < stack_master->a->array[i2])
			return (-1);
	}
	return (i2);
}

int	is_bad_index_only_b(t_stack_master *stack_master)
{
	int	*start_index;
	int	i;
	int	i1;
	int	i2;

	if (ft_stack_is_empty(stack_master->b))
		return (-1);
	i = -1;
	i1 = 0;
	start_index = get_index_of_smallest(stack_master->b, NULL);
	while (++i < stack_master->b->top)
	{
		if (i + *start_index > stack_master->b->top)
			i1 = i + *start_index - stack_master->b->top - 1;
		else
			i1 = i + *start_index;
		if (i + *start_index + 1 > stack_master->b->top)
			i2 = i + *start_index - stack_master->b->top;
		else
			i2 = i + *start_index + 1;
		if (stack_master->b->array[i1] > stack_master->b->array[i2])
			return (-1);
	}
	return (i2);
}
