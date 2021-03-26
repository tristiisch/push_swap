/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:08:51 by tglory            #+#    #+#             */
/*   Updated: 2021/03/26 14:03:37 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	swap;
	int	index;

	if (stack->length < 2)
	{
		printf("WARN > too small length, cancel swap\n");
		return ;
	}
	index = stack->length - 1;
	swap = (stack->array)[index];
	(stack->array)[index] = (stack->array)[index - 1];
	(stack->array)[index - 1] = swap;
}

void	ft_push(t_stack_master *stack_master, int bool)
{
	t_stack	*one;
	t_stack	*two;

	if (bool == 1)
	{
		one = &stack_master->a;
		two = &stack_master->b;
	}
	else
	{
		two = &stack_master->a;
		one = &stack_master->b;
	}
	if (one->length == 0 || (bool != 0 && bool != 1))
	{
		printf("WARN > too small length, cancel push\n");
		return ;
	}
	(two->array)[two->length] = (one->array)[one->length - 1];
	(one->array)[one->length - 1] = 0;
	(one->length)--;
	(two->length)++;
}

void	ft_rotate(t_stack *stack)
{
	int	swap;
	int	index;

	if (stack->length <= 1)
	{
		printf("WARN > too small length, cancel rotate\n");
		return ;
	}
	index = stack->length - 1;
	swap = (stack->array)[index];
	while (--index >= 0)
		(stack->array)[index + 1] = (stack->array)[index];
	(stack->array)[index + 1] = swap;
}

void	ft_reverse_rotate(t_stack *stack)
{
	int		swap;
	size_t	index;

	if (stack->length <= 1)
	{
		printf("WARN > too small length, cancel reverse\n");
		return ;
	}
	index = 0;
	swap = (stack->array)[index];
	while (index < stack->length)
	{
		(stack->array)[index] = (stack->array)[index + 1];
		index++;
	}
	(stack->array)[stack->length - 1] = swap;
}
