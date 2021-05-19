/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/19 08:47:13 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_get_cercle(int index, t_stack *stack)
{
	if (index > stack->top)
		index = index - stack->top - 1;
	return (stack->array[index]);
}

/*
int ft_get_perfect_index_a(t_perfect_stack *perfect_stack, t_stack_master *stack_master)
{
	int i;
	int i1 = stack_master->b->array[stack_master->b->top];
	int i2 = stack_master->b->array[0];
	i = 0;
	while(i <= stack_master->a->top)
	{
		int value = stack_master->a->array[i];

		if ((i1 < value && value < i2) || ((i1 < value || i2 > value)
			&& i2 == perfect_stack->perfect_array_b[0][1]
			&& i1 == perfect_stack->perfect_array_b[perfect_stack->size_b - 1][1]))
		{
			// printf("DEBUG perfect INDEX %d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
}*/
/*
int ft_get_perfect_index_b(int value, int **perfect_stack_array, int perfect_stack_size, t_stack *stackDest)
{
	int i;
	int i1;
	int i2;

	i = 0;
	while(i <= stackDest->top)
	{
		i1 = stackDest->array[i];
		i2 = ft_get_cercle(i + 1, stackDest);
		if ((i1 < value && i2 > value) || ((i1 < value || i2 > value)
			&& i2 == perfect_stack_array[perfect_stack_size - 1][1]
			&& i1 == perfect_stack_array[0][1]))
		{
			//printf("DEBUG perfect INDEX %d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
}
*/
void ft_auto_sortV4(t_stack_master *stack_master)
{
	// t_perfect_stack perfect_stack;
	int top;

	// perfect_stack = ft_get_perfect_stack(stack_master);
	while (!(ft_is_correct(stack_master)))
	{
		int bad_index;
		/*if ((bad_index = is_bad_index_only(stack_master)) > -1) {
			jump_to_index(stack_master, bad_index, 0);
		} else */
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
		else if (stack_master->b->top > 0)
		{
			if (!ft_perfect_shot(stack_master, stack_master->b->array[*get_index_of_smallest(stack_master->b, NULL)],
				stack_master->b->array[*get_index_of_biggest(stack_master->b, NULL)])) {
				ft_warn("Can't sort perfect");
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
