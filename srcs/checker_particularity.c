/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_particularity.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:03:45 by ksam              #+#    #+#             */
/*   Updated: 2021/05/13 17:03:45 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_correct_order(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] < stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_upside_down(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->top)
	{
		if (stack->array[i] > stack->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_correct(t_stack_master *stack_master)
{
	int	i;

	if (ft_stack_is_empty(stack_master->a)
		|| !ft_stack_is_empty(stack_master->b))
		return (0);
	i = 0;
	while (i < stack_master->a->top)
	{
		if (stack_master->a->array[i] < stack_master->a->array[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/** Check if we can revert the 2 first value of stack
 * @param perfect_array get this with ft_get_perfect_stack()
 */
int	ft_can_be_revert(t_stack *stack, int **perfect_array)
{
	int	one;
	int	two;

	if (stack->top <= 0)
		return (0);
	one = stack->array[stack->top];
	two = stack->array[stack->top - 1];
	if (one < two)
		return (0);
	return (can_be_revert_process(stack, perfect_array, one, two));
}

int	can_be_revert_process(t_stack *stack, int **perfect_array, int one, int two)
{
	int	i;
	int	one_index;
	int	two_index;

	i = 0;
	one_index = -1;
	two_index = -1;
	while (i <= stack->top && (one_index == -1 || two_index == -1))
	{
		if (one_index == -1 && perfect_array[i][1] == one)
			one_index = i;
		else if (two_index == -1 && perfect_array[i][1] == two)
			two_index = i;
		i++;
	}
	if (one_index == -1 || two_index == -1)
		return (0);
	else if (one_index + 1 == two_index)
		return (1);
	return (0);
}
