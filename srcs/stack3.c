/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:46:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/24 16:38:37 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_push(t_stack *stack, int item)
{
	if (ft_stack_is_full(stack))
		ft_error("The stack you trying to push on is full");
	stack->array[++stack->top] = item;
}

/**
 * get the last (index 0) int of stack
 */
int	ft_stack_pop(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
		ft_error("The stack you are trying to pop is empty");
	return (stack->array[stack->top--]);
}

/**
 * get the last (index 0) int of stack and remove it
 */
int	ft_stack_peek(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
		ft_error("The stack you are trying to peek is empty");
	return (stack->array[stack->top]);
}
