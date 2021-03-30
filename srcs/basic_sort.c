/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:08:51 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 05:40:20 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int swap;

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
	t_stack	*one;
	t_stack	*two;

	if (bool == 1)
	{
		one = stack_master->a;
		two = stack_master->b;
	}
	else
	{
		one = stack_master->b;
		two = stack_master->a;
	}
	if (ft_stack_is_empty(one) || (bool != 0 && bool != 1))
	{
		printf("WARN > too small length, cancel push\n");
		return ;
	}
	ft_print_stack(two);
	ft_stack_duplicate_push(two, ft_stack_peek(one));
	ft_print_stack(two);
	ft_stack_pop(one);
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
	int		swap;
	int		index;

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
