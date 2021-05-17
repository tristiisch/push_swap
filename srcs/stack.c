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

int	ft_stack_has(t_stack *stack, int item)
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

t_stack	*ft_add(t_stack *stack, char* s)
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

t_stack	*ft_stack_add(t_stack *old_stack, int new_item)
{
	t_stack* new_stack;
	// int	i;
	char out[60];

	new_stack = NULL;
	if (old_stack == NULL)
		new_stack = ft_stack_create(1);
	else if (!(ft_stack_has_place(old_stack, 1)))
	{
		ft_print_stack(old_stack);
		sprintf(out, "The stack is full, can't push on it (size = %d)", old_stack->capacity);
		ft_error(out);
		// new_stack = ft_stack_create(old_stack->capacity + 1);
		// i = 0;
		// while (i <= old_stack->top)
			// ft_stack_push(new_stack, old_stack->array[i++]);
		//ft_stack_free_stack(stack);
		// ft_warn("The precedant stack was not free");
	}
	else
		new_stack = old_stack;
	ft_stack_push(new_stack, new_item);
	return (new_stack);
}

t_stack	*ft_stack_create(unsigned int capacity)
{
	t_stack* stack;

	stack = (t_stack*)malloc(sizeof(t_stack));
	if (stack == NULL)
		ft_error_memomy();
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*)malloc(stack->capacity * sizeof(int));
	if (stack->array == NULL)
		ft_error_memomy();
	return (stack);
}

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
int ft_stack_has_place(t_stack *stack, int i)
{
	return (stack->capacity > stack->top + i);
}

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
