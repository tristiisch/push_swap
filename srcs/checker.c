/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 03:58:32 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 03:58:32 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_bad_index_only(t_stack_master *stack_master)
{
	int	start_index;
	int	i1;
	int	i2;

	if (ft_stack_is_empty(stack_master->a)
		|| !ft_stack_is_empty(stack_master->b))
		return (-1);
	i1 = 0;
	start_index = get_index_of_bigest(stack_master->a->array);
	while (i1 < stack_master->a->top)
	{
		if (i1 + start_index == stack_master->a->top - 1)
			i2 = 0;
		else
			i2 = i1 + start_index + 1;
		if (stack_master->a->array[i1 + start_index]
			< stack_master->a->array[i2])
			return (0);
		i1++;
	}
	return (1);
}

int	is_correct(t_stack_master *stack_master)
{
	int	i;

	if (ft_stack_is_empty(stack_master->a)
		|| !ft_stack_is_empty(stack_master->b))
		return (0);
	i = 0;
	while (i < stack_master->a->top)
	{
		if (stack_master->a->array[i] < stack_master->a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}
