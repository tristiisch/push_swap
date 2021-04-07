/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:08:51 by tglory            #+#    #+#             */
/*   Updated: 2021/04/07 15:27:16 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/**
 * TODO
 * add protection like stack != NULL
 */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	swap;

	if (stack->top < 1)
	{
		printf("WARN > too small length, cancel swap\n");
		return ;
	}
	swap = stack->array[stack->top];
	stack->array[stack->top] = stack->array[stack->top - 1];
	stack->array[stack->top - 1] = swap;
}

void	ft_push(t_stack_master *stack_master, int bool)
{
	if (bool == 1 && !ft_stack_is_empty(stack_master->a))
		stack_master->b = ft_stack_add(stack_master->b,
				ft_stack_pop(stack_master->a));
	else if (bool == 0 && !ft_stack_is_empty(stack_master->b))
		stack_master->a = ft_stack_add(stack_master->a,
				ft_stack_pop(stack_master->b));
	else
	{
		printf("WARN > stack empty or bad parameter `bool`. Push cancelled\n");
		return ;
	}
}

void	ft_rotate(t_stack *stack)
{
	int	swap;
	int	index;

	if (stack->top <= 0)
	{
		printf("WARN > too small length, cancel rotate\n");
		return ;
	}
	index = stack->top;
	swap = (stack->array)[index];
	while (--index >= 0)
		(stack->array)[index + 1] = (stack->array)[index];
	(stack->array)[index + 1] = swap;
}

void	ft_reverse_rotate(t_stack *stack)
{
	int	swap;
	int	index;

	if (stack->top <= 0)
	{
		printf("WARN > too small length, cancel reverse\n");
		return ;
	}
	index = 0;
	swap = (stack->array)[index];
	while (index <= stack->top)
	{
		(stack->array)[index] = (stack->array)[index + 1];
		index++;
	}
	(stack->array)[stack->top] = swap;
}
