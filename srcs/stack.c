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

int ft_stack_has(t_stack *stack, int item)
{
	int	index;

	index = 0;
	while (index <= stack->top)
	{
		if (stack->array[index++] == item)
			return (1);
	}
	return (0);
}

t_stack* ft_add(t_stack *stack, char* s)
{
	int	*i;
	
	i = ft_atoi_utimate(s);
	if (!i)
	{
		printf("Error > %s is not a correct INT.\n", s);
		exit (EXIT_FAILURE);
	}
	else if (ft_stack_has(stack, *i))
	{
		printf("Error > %s (%d) is already on stack A.\n", s, *i);
		exit (EXIT_FAILURE);
	}
	return ft_stack_add(stack, *i);
}

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
		//ft_stack_free_stack(stack);
	}
	else
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
	if (stack->capacity > 0)
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
	{
		printf("ERROR stack is full\n");
		return ;
	}
	stack->array[++stack->top] = item;
	//printf("%d pushed\n", item);
}

int ft_stack_pop(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
	{
		printf("ERROR empty stack\n");
		return (-42);
	}
	return stack->array[stack->top--];
}

int ft_stack_peek(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
	{
		printf("ERROR stack is full\n");
		return (-42);
	}
	return stack->array[stack->top];
}
