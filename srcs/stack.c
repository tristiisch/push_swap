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
		printf("\033[0;31mError\n'%s' is not a correct INT.\033[0m\n", s);
		exit (EXIT_FAILURE);
	}
	else if (ft_stack_has(stack, *i))
	{
		printf("\033[0;31mError\n%d is already on stack A.\033[0m\n", *i);
		exit (EXIT_FAILURE);
	}
	return ft_stack_add(stack, *i);
}

t_stack* ft_stack_add(t_stack *stack, int new_item)
{
	t_stack* new_stack;
	//int	i;

	if (stack == NULL)
		new_stack = ft_stack_create(1);
	else if (!(ft_stack_has_place(stack, 1)))
	{
		ft_error("The stack is full, can't push on it.");
		/*new_stack = ft_stack_create(stack->capacity + 1);
		i = 0;
		while (i <= stack->top)
			ft_stack_push(new_stack, stack->array[i++]);
		ft_stack_free_stack(stack);
		ft_warn("The precedant stack was not free");*/
	}
	else
		new_stack = stack;
	ft_stack_push(new_stack, new_item);
	return (new_stack);
}

t_stack* ft_stack_create(unsigned int capacity)
{
	t_stack* stack;

	stack = (t_stack*)ft_calloc(1, sizeof(t_stack));
	if (stack == NULL)
		ft_error_memomy();
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)ft_calloc(stack->capacity, sizeof(int));
	if (stack->array == NULL)
		ft_error_memomy();
	return (stack);
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
		ft_error("The stack you trying to push on is full\n");
	stack->array[++stack->top] = item;
}

int ft_stack_pop(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
		ft_error("The stack you are trying to pop is empty\n");
	return stack->array[stack->top--];
}

int ft_stack_peek(t_stack *stack)
{
	if (ft_stack_is_empty(stack))
		ft_error("The stack you are trying to peek is empty\n");
	return stack->array[stack->top];
}
