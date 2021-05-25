/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:33:52 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_cercle(int index, t_stack *stack)
{
	if (index > stack->top)
		index = index - stack->top - 1;
	return (stack->array[index]);
}

/**
 * Sort automatically stacks with specific algo
 */
void	ft_auto_sort(t_stack_master *stack_master)
{
	if (stack_master->is_verbose == 1)
		ft_print_master_stack(stack_master);
	ft_auto_sortV5(stack_master);
	if (!ft_is_correct(stack_master))
	{
		ft_warn("Stack_master is not sorted");
		printf("\e[93m");
		ft_print_master_stack(stack_master);
		printf("\e[0m");
	}
	if (stack_master->is_verbose == 1 || stack_master->is_instruction == 1)
	{
		ft_print_instructions(stack_master);
	}
}

void	ft_auto_sortV5_2(t_stack_master *stack_master, int bad_index_a)
{
	int	bad_index_b;

	bad_index_b = is_bad_index_only_b(stack_master);
	if (ft_stack_is_empty(stack_master->a) && bad_index_b > -1)
		jump_to_index(stack_master, bad_index_b, 1);
	else if (bad_index_a > -1)
	{
		ft_perfect_shot_a(stack_master,
			stack_master->a->array[*get_index_of_smallest(
				stack_master->a, NULL)],
			stack_master->a->array[*get_index_of_biggest(
				stack_master->a, NULL)]);
	}
	else if (stack_master->b->top > 0)
	{
		ft_perfect_shot_b(stack_master,
			stack_master->b->array[*get_index_of_smallest(
				stack_master->b, NULL)],
			stack_master->b->array[*get_index_of_biggest(
				stack_master->b, NULL)]);
	}
	else if (stack_master->b->top < 2)
		ft_sort_and_print(stack_master, "pb");
	else
		ft_error("Can't sort with algoV5");
}

void	ft_auto_sortV5(t_stack_master *stack_master)
{
	int	top;
	int	bad_index_a;

	while (!(ft_is_correct(stack_master)))
	{
		bad_index_a = is_bad_index_only_a(stack_master);
		if (ft_stack_is_empty(stack_master->b) && bad_index_a > -1)
			jump_to_index(stack_master, bad_index_a, 0);
		else if (ft_stack_is_empty(stack_master->b)
			&& ft_can_be_revert(stack_master->a))
			ft_sort_and_print(stack_master, "sa");
		else if (ft_stack_is_empty(stack_master->a)
			&& ft_is_upside_down(stack_master->b))
		{
			top = stack_master->b->top;
			while (top-- >= 0)
				ft_sort_and_print(stack_master, "pa");
			break ;
		}
		else
			ft_auto_sortV5_2(stack_master, bad_index_a);
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
			ft_error("Stack B is not sorted");
	}
}
