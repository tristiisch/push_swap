/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 05:09:45 by tglory            #+#    #+#             */
/*   Updated: 2021/04/02 05:09:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	**get_perfect_order(t_stack_master *stack_master, int a_or_b)
{
	int		top;
	int		last_index;
	int		index;
	int		last_number;
	int		i;
	int		**array;
	t_stack	*stack;

	if (a_or_b == 0)
		stack = stack_master->a;
	else if (a_or_b == 1)
		stack = stack_master->b;
	else
	{
		printf("WARN > a_or_b bad parameter `bool`.\
			get_perfect_order cancelled\n");
		return (NULL);
	}
	last_index = -1;
	top = stack->top;
	last_number = -1;
	i = 0;
	if (top >= 0)
		array = malloc((top + 1) * sizeof(*array));
	else
		array = NULL;
	while (i <= top)
	{
		index = get_index_of_biggest(stack, last_number);
		if (index == -1 || last_index == index)
			break ;
		last_index = index;
		last_number = stack->array[index];
		array[i] = malloc(2 * sizeof(int));
		array[i][0] = index;
		array[i][1] = last_number;
		i++;
	}
	return (array);
}

void	ft_free_perfect_stack(t_perfect_stack perfect_stack)
{
	int	i;

	i = 0;
	while (perfect_stack.size_a > i)
		free(perfect_stack.perfect_array_a[i++]);
	free(perfect_stack.perfect_array_a);
	i = 0;
	while (perfect_stack.size_b > i)
		free(perfect_stack.perfect_array_b[i++]);
	free(perfect_stack.perfect_array_b);
}

t_perfect_stack	ft_get_perfect_stack(t_stack_master *stack_master)
{
	t_perfect_stack	perfect_stack;

	perfect_stack.perfect_array_a = get_perfect_order(stack_master, 0);
	perfect_stack.size_a = stack_master->a->top + 1;
	perfect_stack.perfect_array_b = get_perfect_order(stack_master, 1);
	perfect_stack.size_b = stack_master->b->top + 1;
	return (perfect_stack);
}
