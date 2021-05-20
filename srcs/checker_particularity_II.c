/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_particularity_II.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:54:12 by ksam              #+#    #+#             */
/*   Updated: 2021/05/20 15:11:59 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_next_index(t_stack *stack, int index, int *i1, int *i2)
{
	if (index > stack->top)
		*i1 = index - stack->top - 1;
	else
		*i1 = index;
	if (index + 1 > stack->top)
		*i2 = index - stack->top;
	else
		*i2 = index + 1;
}

int	is_bad_index_only_a(t_stack_master *stack_master)
{
	int	*start_index;
	int	i;
	int	i1;
	int	i2;

	if (ft_stack_is_empty(stack_master->a))
		return (-1);
	i = 0;
	i1 = 0;
	start_index = get_index_of_biggest(stack_master->a, NULL);
	while (i < stack_master->a->top)
	{
		get_next_index(stack_master->a, i + *start_index, &i1, &i2);
		if (i1 < 0 || i2 < 0 || i1 > stack_master->a->top
			|| i2 > stack_master->a->top)
			ft_error_master(stack_master, "Checking bad index only "
				"failed, the comparison is outside the range of stack A");
		if (stack_master->a->array[i1] < stack_master->a->array[i2])
			return (-1);
		i++;
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
	i = 0;
	i1 = 0;
	start_index = get_index_of_smallest(stack_master->b, NULL);
	while (i < stack_master->b->top)
	{
		get_next_index(stack_master->b, i + *start_index, &i1, &i2);
		if (i1 < 0 || i2 < 0 || i1 > stack_master->b->top
			|| i2 > stack_master->b->top)
			ft_error_master(stack_master, "Checking bad index only failed, "
				"the comparison is outside the range of stack B");
		if (stack_master->b->array[i1] > stack_master->b->array[i2])
			return (-1);
		i++;
	}
	return (i2);
}
