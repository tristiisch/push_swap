/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:17:57 by tglory            #+#    #+#             */
/*   Updated: 2021/05/14 04:04:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_auto_sortV1(t_stack_master *stack_master)
{
	t_perfect_stack perfect_stack;
	int	top;
	int	max_instruction; // TODO remove max instruction

	perfect_stack = ft_get_perfect_stack(stack_master);
	max_instruction = 0;
	while (!(ft_is_correct(stack_master)))
	{
		int bad_index;
		if (ft_stack_is_empty(stack_master->b) && (bad_index = is_bad_index_only(stack_master)) > -1) {
			jump_to_index(stack_master, bad_index, 0);
		}
		else if (ft_is_upside_down(stack_master->b) && (ft_stack_is_empty(stack_master->a) || ft_is_correct_order(stack_master->a)))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				ft_sort_and_print(stack_master, "pa");
				top--;
			}
		} else if (stack_master->algo_version == 3 && ft_stack_is_empty(stack_master->a) && (bad_index = is_bad_index_only_b(stack_master)) > -1){
			jump_to_index(stack_master, bad_index, 1);
		}
		else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] == stack_master->a->top)
			ft_sort_and_print(stack_master, "pb");
		else if (stack_master->algo_version == 3 && perfect_stack.size_a > 1 && perfect_stack.perfect_array_a[0][0] == stack_master->a->top)
		{
			ft_sort_and_print(stack_master, "pb");
			if (stack_master->b->top > 0) {
				ft_sort_and_print(stack_master, "rb");
			}
		}
		/* Essaie d'utiliser sb. Résultat : Pas opti*/
		else if (stack_master->algo_version == 2 && perfect_stack.size_a > 1 && perfect_stack.perfect_array_a[perfect_stack.size_a - 2][0] == stack_master->a->top)
		{
			//printf("NEW ONE %d\n", stack_master->a->top);
			ft_sort_and_print(stack_master, "pb");
			//perfect_stack = ft_get_perfect_stack(stack_master);
			while (perfect_stack.perfect_array_a[perfect_stack.size_a - 1][1] != stack_master->a->array[stack_master->a->top])
			{
				if (perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] > stack_master->a->top / 2)
					ft_sort_and_print(stack_master, "ra");
				else
					ft_sort_and_print(stack_master, "rra");
				//printf("PERFECT STACK %d - %d\n", perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0], stack_master->a->top);
			}
			ft_sort_and_print(stack_master, "pb");
			ft_sort_and_print(stack_master, "sb");
		}
		else if (perfect_stack.size_a >= 2 && ft_can_be_revert(stack_master->a, perfect_stack.perfect_array_a))
			ft_sort_and_print(stack_master, "sa");
		else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] > stack_master->a->top / 2)
			ft_sort_and_print(stack_master, "ra");
		else {
			ft_sort_and_print(stack_master, "rra");
		}
		ft_free_perfect_stack(perfect_stack);
		perfect_stack = ft_get_perfect_stack(stack_master);
		max_instruction++;
	}
	max_instruction = 0;
	ft_free_perfect_stack(perfect_stack);
}

/** 
 * Sort automatically stacks with specific algo
 */
void	ft_auto_sort(t_stack_master *stack_master)
{
	if (stack_master->is_verbose == 1)
		ft_print_master_stack(stack_master);
	if (stack_master->algo_version == 4)
		ft_auto_sortV4(stack_master);
	else
		ft_auto_sortV1(stack_master);
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