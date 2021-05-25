/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:08:51 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:34:23 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * TODO
 * add protection like stack != NULL
 */

#include "../includes/push_swap.h"

int	ft_swap(t_stack *stack)
{
	int	swap;

	if (stack == NULL)
		return (-1);
	if (stack->top < 1)
		return (0);
	swap = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = swap;
	return (1);
}

int	ft_push(t_stack_master *stack_master, int bool)
{
	if (bool == 1 && !ft_stack_is_empty(stack_master->a))
		stack_master->b = ft_stack_add(stack_master->b,
				ft_stack_pop(stack_master->a));
	else if (bool == 0 && !ft_stack_is_empty(stack_master->b))
		stack_master->a = ft_stack_add(stack_master->a,
				ft_stack_pop(stack_master->b));
	else if (bool == 0 || bool == 1)
		return (0);
	else
		return (-3);
	return (1);
}

int	ft_rotate(t_stack *stack)
{
	int	swap;
	int	index;

	if (stack == NULL)
		return (-1);
	if (stack->top <= 0)
		return (0);
	index = stack->top;
	swap = (stack->array)[index];
	while (--index >= 0)
		(stack->array)[index + 1] = (stack->array)[index];
	(stack->array)[index + 1] = swap;
	return (1);
}

int	ft_reverse_rotate(t_stack *stack)
{
	int	swap;
	int	index;

	if (stack == NULL)
		return (-1);
	if (stack->top <= 0)
		return (0);
	index = 0;
	swap = (stack->array)[index];
	while (index < stack->top)
	{
		(stack->array)[index] = (stack->array)[index + 1];
		index++;
	}
	(stack->array)[stack->top] = swap;
	return (1);
}
