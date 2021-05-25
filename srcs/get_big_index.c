/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_big_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 05:09:45 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:36:59 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** Get the index of the biggest number of stack
 * @param under is the highest non-inclusive number that can be taken.
 * NULL if didn't need.
 * @return NULL if the index cannot be retrive
 */
int	*get_index_of_biggest(t_stack *stack, int *under)
{
	int	index;
	int	*saved_index;
	int	*saved_int;
	int	swap;

	index = stack->top;
	saved_int = NULL;
	saved_index = NULL;
	while (index >= 0)
	{
		if ((!under || stack->array[index] < *under)
			&& (!saved_int || *saved_int < stack->array[index]))
		{
			saved_int = &(stack->array[index]);
			swap = index;
			saved_index = &swap;
		}
		index--;
	}
	return (saved_index);
}

int	*get_index_of_smallest(t_stack *stack, int *upper)
{
	int	index;
	int	*saved_index;
	int	*saved_int;
	int	swap;

	index = stack->top;
	saved_int = NULL;
	saved_index = NULL;
	while (index >= 0)
	{
		if ((!upper || stack->array[index] > *upper)
			&& (!saved_int || *saved_int > stack->array[index]))
		{
			saved_int = &(stack->array[index]);
			swap = index;
			saved_index = &swap;
		}
		index--;
	}
	return (saved_index);
}
