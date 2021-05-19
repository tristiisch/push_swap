/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/19 08:49:42 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_perfect_shot(t_stack_master *stack_master, int min_b, int max_b)
{
	int	i_b;
	int	saved_a;
	int	i_a;
	int	saved_b;
	int	times_a;
	int	times_b;
	int	times_total;
	int	stack_value1;
	int	stack_value2;
	int	value;

	i_b = 0;
	times_a = -1;
	times_b = -1;
	times_total = -1;
	while (i_b <= stack_master->b->top)
	{
		stack_value1 = ft_get_cercle(i_b, stack_master->b);
		stack_value2 = ft_get_cercle(i_b + 1, stack_master->b);
		i_a = 0;
		while (i_a <= stack_master->a->top)
		{
			value = stack_master->a->array[i_a];
			if ((stack_value1 < value && value < stack_value2)
				|| ((stack_value1 < value || stack_value2 > value)
					&& stack_value2 == min_b && stack_value1 == max_b))
			{
				times_a = index_to_times(i_a, stack_master->a->top);
				times_b = index_to_times(i_b, stack_master->b->top);
				if (times_a + times_b == 0 || times_total == -1
					|| times_a + times_b < times_total)
				{
					times_total = times_a + times_b;
					saved_a = i_a;
					saved_b = i_b;
				}
			}
			i_a++;
		}
		i_b++;
	}
	if (times_total < 0)
	{
		ft_error("cannot find");
		return (0);
	}
	jump_to_index_both(stack_master, saved_a, saved_b);
	ft_sort_and_print(stack_master, "pb");
	return (1);
}

int	ft_perfect_shot_a(t_stack_master *stack_master, int min_a, int max_a)
{
	int	i_b;
	int	saved_a;
	int	i_a;
	int	saved_b;
	int	times_a;
	int	times_b;
	int	times_total;
	int	stack_value1;
	int	stack_value2;
	int	value;

	i_a = 0;
	times_total = -1;
	while (i_a <= stack_master->a->top)
	{
		stack_value1 = ft_get_cercle(i_a, stack_master->a);
		stack_value2 = ft_get_cercle(i_a + 1, stack_master->a);
		i_b = 0;
		while (i_b <= stack_master->b->top)
		{
			value = stack_master->b->array[i_b];
			if ((stack_value1 > value && value > stack_value2)
				|| ((stack_value1 > value || stack_value2 < value)
					&& stack_value2 == max_a && stack_value1 == min_a))
			{
				times_a = index_to_times(i_a, stack_master->a->top);
				times_b = index_to_times(i_b, stack_master->b->top);
				if (times_a + times_b == 0 || times_total == -1
					|| times_a + times_b < times_total)
				{
					times_total = times_a + times_b;
					saved_a = i_a;
					saved_b = i_b;
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

void	ft_auto_sortV5(t_stack_master *stack_master)
{
	int	top;
	int	bad_index;

	while (!(ft_is_correct(stack_master)))
	{
		bad_index = is_bad_index_only(stack_master);
		if (ft_stack_is_empty(stack_master->b))
		{
			if (bad_index > -1)
			{
				jump_to_index(stack_master, bad_index, 0);
				continue ;
			}
			else if (ft_can_be_revert(stack_master->a))
			{
				ft_sort_and_print(stack_master, "sa");
				continue ;
			}
		}
		bad_index = is_bad_index_only_b(stack_master);
		if (ft_is_upside_down(stack_master->b)
			&& (ft_stack_is_empty(stack_master->a)))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				ft_sort_and_print(stack_master, "pa");
				top--;
			}
			break ;
		}
		else if (ft_stack_is_empty(stack_master->a) && bad_index > -1)
			jump_to_index(stack_master, bad_index, 1);
		else if (is_bad_index_only(stack_master) > -1)
		{
			if (!ft_perfect_shot_a(stack_master,
					stack_master->a->array[*get_index_of_smallest(
							stack_master->a, NULL)],
					stack_master->a->array[*get_index_of_biggest(
							stack_master->a, NULL)]))
				ft_warn("Can't sort perfect a");
		}
		else if (stack_master->b->top > 0)
		{
			if (!ft_perfect_shot(stack_master,
					stack_master->b->array[*get_index_of_smallest(
							stack_master->b, NULL)],
					stack_master->b->array[*get_index_of_biggest(
							stack_master->b, NULL)]))
				ft_warn("Can't sort perfect b");
		}
		else if (stack_master->b->top < 2)
			ft_sort_and_print(stack_master, "pb");
		else
			ft_error("Can't sort");
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
			ft_error("Stack B is not sorted");
	}
}
