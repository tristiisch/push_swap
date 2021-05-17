/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/17 07:39:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


int ft_perfect_shot_a(t_stack_master *stack_master, int min_a, int max_a)
{
	int i_b;
	int saved_a;
	int i_a;
	int saved_b;
	int times_a;
	int times_b;
	int times_total;

	i_a = 0;
	times_a = -1;
	times_b = -1;
	times_total = -1;
	while(i_a <= stack_master->a->top)
	{
		int stack_value1 = ft_get_cercle(i_a, stack_master->a);
		int stack_value2 = ft_get_cercle(i_a + 1, stack_master->a);
		i_b = 0;
		while(i_b <= stack_master->b->top)
		{
			int value = stack_master->b->array[i_b];
			if ((stack_value1 > value && value > stack_value2) || ((stack_value1 > value || stack_value2 < value)
				// && stack_value2 == perfect_stack->perfect_array_b[stack_master->b->top][1]
				// && stack_value1 == perfect_stack->perfect_array_b[0][1]))
				&& stack_value2 == max_a
				&& stack_value1 == min_a))
				// && stack_value2 == *get_index_of_smallest(stack_master->b, NULL)
				// && stack_value1 == *get_index_of_biggest(stack_master->b, NULL)))
			{
				// printf("DEBUG stack_value1 %d-%d stack_value2 %d-%d\n", *get_index_of_biggest(stack_master->b, NULL), max_b,
				// *get_index_of_smallest(stack_master->b, NULL), min_b);
				int times_a_2 = index_to_times(i_a, stack_master->a->top);
				int times_b_2 = index_to_times(i_b, stack_master->b->top);
				if (times_a_2 + times_b_2 == 0 || times_total == -1 || times_a_2 + times_b_2 < times_total)
				{
					times_total = times_a_2 + times_b_2;
					saved_a = i_a;
					saved_b = i_b;
					times_a = times_a_2;
					times_b = times_b_2;
				}
			}
			i_b++;
		}
		i_a++;
	}
	if (times_total < 0)
	{
		ft_error("cannot find");
		return (0);
	}
	jump_to_index_both(stack_master, saved_a, saved_b);
	ft_sort_and_print(stack_master, "pa");
	return (1);
}

void ft_auto_sortV5(t_stack_master *stack_master)
{
	// t_perfect_stack perfect_stack;
	int top;
	int bad_index;

	// perfect_stack = ft_get_perfect_stack(stack_master);
	while (!(ft_is_correct(stack_master)))
	{
		bad_index = is_bad_index_only(stack_master);
		if (ft_stack_is_empty(stack_master->b)) {
			if (bad_index > -1) {
				jump_to_index(stack_master, bad_index, 0);
				continue;
			}
			else if (ft_can_be_revert(stack_master->a, ft_get_perfect_stack(stack_master).perfect_array_a)) {
				ft_sort_and_print(stack_master, "sa");
				continue;
			}
		}
		if (ft_is_upside_down(stack_master->b) && (ft_stack_is_empty(stack_master->a) /*|| ft_is_correct_order(stack_master->a)*/))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				ft_sort_and_print(stack_master, "pa");
				top--;
			}
			break;
		}
		else if (ft_stack_is_empty(stack_master->a) && (bad_index = is_bad_index_only_b(stack_master)) > -1)
		{
			jump_to_index(stack_master, bad_index, 1);
		}
		else if (is_bad_index_only(stack_master) > -1)
		{
			if (!ft_perfect_shot_a(stack_master, stack_master->a->array[*get_index_of_smallest(stack_master->a, NULL)],
				stack_master->a->array[*get_index_of_biggest(stack_master->a, NULL)])) {
				ft_warn("Can't sort perfect a");
			}
		}
		else if (stack_master->b->top > 0)
		{
			if (!ft_perfect_shot(stack_master, stack_master->b->array[*get_index_of_smallest(stack_master->b, NULL)],
				stack_master->b->array[*get_index_of_biggest(stack_master->b, NULL)])) {
				ft_warn("Can't sort perfect b");
			}
		}
		else if (stack_master->b->top < 2)
			ft_sort_and_print(stack_master, "pb");
		else {
			ft_error("Can't sort");
		}
		// ft_free_perfect_stack(perfect_stack);
		// perfect_stack = ft_get_perfect_stack(stack_master);
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
		{
			ft_error("Stack B is not sorted");
		}
	}
	// ft_free_perfect_stack(perfect_stack);
}
