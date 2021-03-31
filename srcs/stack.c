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

t_stack* ft_stack_add(t_stack *stack, int new_item)
{
	t_stack* new_stack;
	int	i;

	if (stack == NULL)
		new_stack = ft_stack_create(1);
	else if (!(ft_stack_has_place(stack, 1)))
	{
		new_stack = ft_stack_create(stack->capacity + 1);
		i = 0;
		while (i <= stack->top)
			ft_stack_push(new_stack, stack->array[i++]);
		ft_stack_free_stack(stack);
	} else
		new_stack = stack;
	ft_stack_push(new_stack, new_item);
	return new_stack;
}

t_stack* ft_stack_create(unsigned int capacity)
{
	t_stack* stack;

	stack = (t_stack*)malloc(sizeof(t_stack)); // TODO protect malloc
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int)); // TODO same
	return stack;
}

void ft_stack_free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

int ft_stack_is_full(t_stack *stack)
{
	return stack->top == stack->capacity - 1;
}

int ft_stack_is_empty(t_stack *stack)
{
	return stack->top == -1;
}

int ft_stack_has_place(t_stack *stack, int i)
{
	return stack->capacity > stack->top + i;
}

void ft_stack_push(t_stack *stack, int item)
{
	if (ft_stack_is_full(stack))
		return;
	stack->array[++stack->top] = item;
	//printf("%d pushed\n", item);
}

int ft_stack_pop(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
		return -42;
	return stack->array[stack->top--];
}

int ft_stack_peek(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
		return -42;
	return stack->array[stack->top];
}
