/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 04:46:08 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 04:16:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack* ft_stack_duplicate_push(t_stack* old_stack, int new_item)
{
	t_stack* new_stack;
	int	i;

	if (old_stack != NULL)
	{
		new_stack = ft_stack_create(old_stack->capacity + 1);
		i = 0;
		while (i <= old_stack->top)
			ft_stack_push(new_stack, old_stack->array[i++]);
		free(old_stack->array);
		free(old_stack);
	} else
		new_stack = ft_stack_create(1);
	ft_stack_push(new_stack, new_item);
	return new_stack;
}

t_stack* ft_stack_create(unsigned capacity)
{
	t_stack* stack;

	stack = (t_stack*)malloc(sizeof(t_stack)); // TODO protect malloc
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); // TODO same
	return stack;
}

int ft_stack_is_full(t_stack* stack)
{
	return stack->top == stack->capacity - 1;
}

int ft_stack_is_empty(t_stack* stack)
{
	return stack->top == -1;
}

void ft_stack_push(t_stack* stack, int item)
{
	if (ft_stack_is_full(stack))
		return;
	stack->array[++stack->top] = item;
	printf("%d pushed\n", item);
}

int ft_stack_pop(t_stack* stack)
{
	if (ft_stack_is_empty(stack))
		return INT_MIN;
	return stack->array[stack->top--];
}

int ft_stack_peek(t_stack* stack)
{
	if (ft_stack_is_empty(stack))
		return INT_MIN;
	return stack->array[stack->top];
}
