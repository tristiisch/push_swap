/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:08:51 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 16:03:48 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *array, size_t length)
{
	int	swap;
	int	index;

	if (length < 2)
	{
		printf("WARN > too small length, cancel swap\n");
		return ;
	}
	index = length - 1;
	swap = array[index];
	array[index] = array[index - 1];
	array[index - 1] = swap;
}

void	ft_push(t_stack *stack, int bool)
{
	int		**array_one;
	int		**array_two;
	size_t	*length_one;
	size_t	*length_two;

	if (bool == 1)
	{
		array_one = &stack->array_a;
		length_one = &stack->length_a;
		array_two = &stack->array_b;
		length_two = &stack->length_b;
	}
	else
	{
		array_one = &stack->array_b;
		length_one = &stack->length_b;
		array_two = &stack->array_a;
		length_two = &stack->length_a;
	}
	if (*length_one == 0)
	{
		printf("WARN > out of limit, cancel push\n");
		return ;
	}
	(*array_two)[*length_two] = (*array_one)[*length_one - 1];
	(*array_one)[*length_one - 1] = 0;
	(*length_one)--;
	(*length_two)++;
}
