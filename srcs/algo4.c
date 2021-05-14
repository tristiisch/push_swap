/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/14 02:45:46 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int ft_get_cercle(int index, t_stack *stack)
{
	if (index > stack->top)
		index = index - stack->top - 1;
	return (stack->array[index]);
}

int ft_get_perfect_index(int value, int **perfect_stack_array, int perfect_stack_size, t_stack *stackDest)
{
	int i;

	i = 0;
	while(i <= stackDest->top)
	{
		if ((stackDest->array[i] < value && ft_get_cercle(i + 1, stackDest) > value) 
			|| ((stackDest->array[i] < value || ft_get_cercle(i + 1, stackDest) > value)
			&& ft_get_cercle(i + 1, stackDest) == perfect_stack_array[perfect_stack_size - 1][1] 
			&& stackDest->array[i] == perfect_stack_array[0][1]))
		{
			//printf("DEBUG perfect INDEX %d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
	/*i = perfect_stack->size_b;
	while (i--)
	{
		if (perfect_stack->perfect_array_b[i][1] < value && (perfect_stack->size_b == i + 1 || perfect_stack->perfect_array_b[i + 1][1] > value))
		{
			//printf("TEST %d > %d INDEX %d\n", perfect_stack->size_b, perfect_stack->perfect_array_b[i][1], perfect_stack->perfect_array_b[i][0]);
			if (perfect_stack->size_b != i + 1)
				printf("THE PERFECT INDEX IS index %d - %d VALUE %d\n", perfect_stack->perfect_array_b[i][0], perfect_stack->perfect_array_b[i + 1][0], perfect_stack->perfect_array_b[i][1]);
			return (perfect_stack->perfect_array_b[i][0]);
		}
	}*/
}

void ft_auto_sortV4(t_stack_master *stack_master)
{
	t_perfect_stack perfect_stack;
	int top;
	int max_instruction; // TODO remove max instruction

	perfect_stack = ft_get_perfect_stack(stack_master);
	max_instruction = 0;
	while (!(ft_is_correct(stack_master)))
	{
		int bad_index;
		/*if ((bad_index = is_bad_index_only(stack_master)) > -1) {
			jump_to_index(stack_master, bad_index, 0);
		}
		else */
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
		/*else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] == stack_master->a->top)
			ft_sort_and_print(stack_master, "pb");
		else if (perfect_stack.size_a > 1 && perfect_stack.perfect_array_a[0][0] == stack_master->a->top)
		{
			ft_sort_and_print(stack_master, "pb");
			if (stack_master->b->top > 0) {
				ft_sort_and_print(stack_master, "rb");
			}
		}*/
		else if (stack_master->b->top >= 1)
		{
			int inde = ft_get_perfect_index(stack_master->a->array[stack_master->a->top], perfect_stack.perfect_array_b, perfect_stack.size_b, stack_master->b);
			if (inde == -1)
				ft_error("can't find perfect index on B");
			//printf("DEBUG index %d\n", inde);
			jump_to_index(stack_master, inde, 1);
			/*int value = stack_master->b->array[inde];
			while (!((stack_master->b->array[stack_master->b->top] < stack_master->a->array[stack_master->a->top] 
				&& stack_master->b->array[0] > stack_master->a->array[stack_master->a->top]) 
				|| (stack_master->b->top != 1 && stack_master->b->array[stack_master->b->top] < stack_master->a->array[stack_master->a->top] 
				&& stack_master->b->array[0] == perfect_stack.perfect_array_b[perfect_stack.size_b - 1][1] 
				&& stack_master->b->array[stack_master->b->top] == perfect_stack.perfect_array_b[0][1])))
			{
				ft_sort_and_print(stack_master, "rb");
			}
			if (value == stack_master->b->array[stack_master->b->top])
			{
				printf("DEBUG good\n");
			} else
			{
				printf("DEBUG bad\n");
			}*/
			ft_sort_and_print(stack_master, "pb");
		}
		else if (stack_master->b->top == 0)
		{
			ft_sort_and_print(stack_master, "pb");
			/*if (stack_master->b->array[0] < stack_master->b->array[1]) {
					ft_sort_and_print(stack_master, "sb");
				}*/
		}
		else
		{
			ft_sort_and_print(stack_master, "pb");
		}
		ft_free_perfect_stack(perfect_stack);
		perfect_stack = ft_get_perfect_stack(stack_master);
		max_instruction++;
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
		{
			ft_warn("Stack B is not sorted");
		}
	}
	ft_free_perfect_stack(perfect_stack);
}
