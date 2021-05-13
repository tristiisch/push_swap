/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 17:54:46 by tglory            #+#    #+#             */
/*   Updated: 2021/05/13 17:55:20 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_get_perfect_index(int value, t_perfect_stack *perfect_stack)
{
	int	i;

	i = perfect_stack->size_b;
	while (i--)
	{
		if (perfect_stack->perfect_array_b[i][1] < value && (perfect_stack->size_b == i + 1 || perfect_stack->perfect_array_b[i + 1][1] > value))
		{
			//printf("TEST %d > %d INDEX %d\n", perfect_stack->size_b, perfect_stack->perfect_array_b[i][1], perfect_stack->perfect_array_b[i][0]);
			if (perfect_stack->size_b != i + 1)
				printf("THE PERFECT INDEX IS index %d - %d VALUE %d\n", perfect_stack->perfect_array_b[i][0], perfect_stack->perfect_array_b[i + 1][0], perfect_stack->perfect_array_b[i][1]);
			return (perfect_stack->perfect_array_b[i][0]);
		}
	}
	return (-1);
}

void	ft_auto_sort2(t_stack_master *stack_master)
{
	t_perfect_stack	perfect_stack;
	int	top;
	int	max_instruction; // TODO remove max instruction

	if (stack_master->is_verbose == 1)
		ft_print_master_stack(stack_master);
	perfect_stack = ft_get_perfect_stack(stack_master);
	max_instruction = 0;
	while (!(ft_is_correct(stack_master)) && max_instruction < 100)
	{
		int bad_index;
		if ((bad_index = is_bad_index_only(stack_master)) > -1) {
			jump_to_index(stack_master, bad_index, 0);
		}
		else if (ft_is_updside_down(stack_master->b) && (ft_stack_is_empty(stack_master->a) || ft_is_correct_order(stack_master->a)))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				ft_sort_and_print(stack_master, "pa");
				top--;
			}
			break;
		} else if (stack_master->algo_version >= 3 && (bad_index = is_bad_index_only_b(stack_master)) > -1){
			jump_to_index(stack_master, bad_index, 1);
		}
		/*else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] == stack_master->a->top)
			ft_sort_and_print(stack_master, "pb");
		else if (perfect_stack.size_a > 1 && perfect_stack.perfect_array_a[0][0] == stack_master->a->top)
		{
			ft_sort_and_print(stack_master, "pb");
			if (stack_master->b->top > 0) {
				ft_sort_and_print(stack_master, "rb");
			}
		}*/
		else if (perfect_stack.size_a > 0/* && perfect_stack.perfect_array_a[perfect_stack.size_a - 1 - 10][1] > stack_master->a->array[stack_master->a->top]*/)
		{
			int index = ft_get_perfect_index(stack_master->a->array[stack_master->a->top], &perfect_stack);
			printf("INDEX %d\n", index);
			if (index >= 1)
			{
				jump_to_index(stack_master, index, 1);
				ft_sort_and_print(stack_master, "pb");
				ft_sort_and_print(stack_master, "sb");
			} 
			else if (index == 0)
			{
				ft_sort_and_print(stack_master, "pb");
				ft_sort_and_print(stack_master, "sb");
			} else {
				ft_sort_and_print(stack_master, "pb");
			}
			/*if (index == -1 && stack_master->b->top >= 1)
				ft_sort_and_print(stack_master, "rb");*/
			//printf("smallest %d\n", get_index_of_smallest(stack_master->b, -1));
			//jump_to_index(stack_master, get_index_of_smallest(stack_master->b, -1), 1);

		}
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
	if (stack_master->is_verbose == 1 || stack_master->is_instruction == 1)
		printf("instructions algo n°%d > %d\n", stack_master->algo_version, stack_master->instructions);
	ft_free_perfect_stack(perfect_stack);
	ft_stack_free_stack(stack_master->a);
	ft_stack_free_stack(stack_master->b);
}