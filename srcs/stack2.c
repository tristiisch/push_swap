/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:46:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/24 16:38:35 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stack_free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	if (stack->capacity > 0)
		free(stack->array);
	free(stack);
}

int	ft_stack_is_full(t_stack *stack)
{
	return (stack->top == stack->capacity - 1);
}

int	ft_stack_is_empty(t_stack *stack)
{
	return (stack->top == -1);
}

/**
 * if momory is allocated for @param i objects
 */
int	ft_stack_has_place(t_stack *stack, int i)
{
	return (stack->capacity > stack->top + i);
}
