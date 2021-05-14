/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_particularity_II.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:54:12 by ksam              #+#    #+#             */
/*   Updated: 2021/05/14 10:36:25 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int is_bad_index_only(t_stack_master *stack_master)
{
	int *start_index;
	int i;
	int i1;
	int i2;

	/*if (ft_stack_is_empty(stack_master->a) || !ft_stack_is_empty(stack_master->b))
		return (-1);*/
	if (ft_stack_is_empty(stack_master->a))
		return (-1);
	i = 0;
	i1 = 0;
	start_index = get_index_of_biggest(stack_master->a, NULL);
	while (i < stack_master->a->top)
	{
		if (i + *start_index > stack_master->a->top)
			i1 = i + *start_index - stack_master->a->top - 1;
		else
			i1 = i + *start_index;
		if (i + *start_index + 1 > stack_master->a->top)
			i2 = i + *start_index - stack_master->a->top;
		else
			i2 = i + *start_index + 1;
		if (i1 < 0 || i2 < 0 || i1 > stack_master->a->top || i2 > stack_master->a->top)
			ft_error_master(stack_master, "Checking bad index only failed, the comparison is outside the range of stack A");
		if (stack_master->a->array[i1] < stack_master->a->array[i2])
			return (-1);
		i++;
	}
	return (i2);
}

int is_bad_index_only_b(t_stack_master *stack_master)
{
	int *start_index;
	int i;
	int i1;
	int i2;

	/*if (!ft_stack_is_empty(stack_master->a)
		|| ft_stack_is_empty(stack_master->b))*/
	if (ft_stack_is_empty(stack_master->b))
		return (-1);
	i = 0;
	i1 = 0;
	start_index = get_index_of_smallest(stack_master->b, NULL);
	//printf("DEBUG_only_b %d\n", *start_index);
	while (i < stack_master->b->top)
	{
		if (i + *start_index > stack_master->b->top)
			i1 = i + *start_index - stack_master->b->top - 1;
		else
			i1 = i + *start_index;
		if (i + *start_index + 1 > stack_master->b->top)
			i2 = i + *start_index - stack_master->b->top;
		else
			i2 = i + *start_index + 1;
		//printf("DEBUG3 %d %d\n", i1, i2);
		if (i1 < 0 || i2 < 0 || i1 > stack_master->b->top || i2 > stack_master->b->top)
			ft_error_master(stack_master, "Checking bad index only failed, the comparison is outside the range of stack B");
		if (stack_master->b->array[i1] > stack_master->b->array[i2])
			return (-1);
		i++;
	}
	return (i2);
}

int is_bad_index_only_bOLD(t_stack_master *stack_master)
{
	int *start_index;
	int i;
	int i1;
	int i2;

	if (!ft_stack_is_empty(stack_master->a) || ft_stack_is_empty(stack_master->b))
		return (-1);
	i = 0;
	i1 = 0;
	start_index = get_index_of_biggest(stack_master->b, NULL);
	//printf("DEBUG start_index %d\n", *start_index);
	while (i < stack_master->b->top)
	{
		//printf("DEBUG2 %d\n", i);
		if (*start_index - i < 0)
			i1 = *start_index - i + stack_master->b->top + 1;
		else
			i1 = *start_index - i;
		if (*start_index - i - 1 < 0)
			i2 = *start_index - i + stack_master->b->top;
		else
			i2 = *start_index - i - 1;
		//printf("DEBUG3 %d %d\n", i1, i2);
		if (i1 < 0 || i2 < 0 || i1 > stack_master->b->top || i2 > stack_master->b->top)
			ft_error_master(stack_master, "Checking bad index only failed, the comparison is outside the range of stack B");
		if (stack_master->b->array[i1] < stack_master->b->array[i2])
			return (-1);
		i++;
	}
	return (*start_index);
}