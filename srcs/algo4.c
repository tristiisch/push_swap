/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:08 by tglory            #+#    #+#             */
/*   Updated: 2021/05/14 09:22:57 by tglory           ###   ########lyon.fr   */
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
int ft_get_perfect_index_a(int value, int **perfect_stack_array, int perfect_stack_size, t_stack *stackDest)
{
	int i;

	i = 0;
	while(i <= stackDest->top)
	{
		if ((stackDest->array[i] > value && ft_get_cercle(i + 1, stackDest) < value) 
			|| ((stackDest->array[i] > value || ft_get_cercle(i + 1, stackDest) < value)
			&& ft_get_cercle(i + 1, stackDest) == perfect_stack_array[0][1] 
			&& stackDest->array[i] == perfect_stack_array[perfect_stack_size - 1][1]))
		{
			//printf("DEBUG perfect INDEX %d\n", i);
			return (i);
		}
		i++;
	}
	return (-1);
}*/

int ft_perfect_shot(t_stack_master *stack_master, int min_b, int max_b)
{
	int i_a;
	int saved_a;
	int i_b;
	int saved_b;
	int times_a;
	int times_b;
	int times_total;

	i_b = 0;
	times_a = -1;
	times_b = -1;
	times_total = -1;
	while(i_b <= stack_master->b->top)
	{
		int stack_value1 = ft_get_cercle(i_b, stack_master->b);
		int stack_value2 = ft_get_cercle(i_b + 1, stack_master->b);
		i_a = 0;
		while(i_a <= stack_master->a->top)
		{
			int value = stack_master->a->array[i_a];
			if ((stack_value1 < value && value < stack_value2) || ((stack_value1 < value || stack_value2 > value)
				// && stack_value2 == stack_master->b->array[0]
				// && stack_value1 == stack_master->b->array[stack_master->b->top]))
				// && stack_value2 == perfect_stack->perfect_array_b[stack_master->b->top][1]
				// && stack_value1 == perfect_stack->perfect_array_b[0][1]))
				&& stack_value2 == min_b
				&& stack_value1 == max_b))
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
			i_a++;
		}
		i_b++;
	}
	if (times_total < 0)
	{
		ft_error("cannot find");
		return (0);
		
	}
	// printf("Yess %d A:%d B:%d Index A:%d B:%d Top A:%d B:%d Value A:%d B:%d\n", times_total, times_a, 
	// times_b, saved_a, saved_b, stack_master->a->top, stack_master->b->top, stack_master->a->array[saved_a], stack_master->b->array[saved_b]);
	if (saved_a != stack_master->a->top)
		jump_to_index(stack_master, saved_a, 0);
	if (saved_b != stack_master->b->top)
		jump_to_index(stack_master, saved_b, 1);
	ft_sort_and_print(stack_master, "pb");
	return (1);
}

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
}

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
		else if (stack_master->b->top > 0)
		{
			if (ft_perfect_shot(stack_master, perfect_stack.perfect_array_b[stack_master->b->top][1], perfect_stack.perfect_array_b[0][1]) == 0) {
				ft_warn("Can't sort perfect");
				// int index_b = ft_get_perfect_index_b(stack_master->a->array[stack_master->a->top], perfect_stack.perfect_array_b, perfect_stack.size_b, stack_master->b);
				// if (index_b == -1)
				// 	ft_error("Can't find perfect index on B");
				// jump_to_index(stack_master, index_b, 1);
				// ft_sort_and_print(stack_master, "pb");
			}
		}
		else if (stack_master->b->top < 2)
		{
			ft_sort_and_print(stack_master, "pb");
		} else {
			ft_error("Can't sort");
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
		/*else if (stack_master->b->top >= 1)
		{
			int index_b = ft_get_perfect_index_b(stack_master->a->array[stack_master->a->top], perfect_stack.perfect_array_b, perfect_stack.size_b, stack_master->b);
			if (index_b == -1)
				ft_error("Can't find perfect index on B");
			int times_b = index_to_times(index_b, stack_master->b->top);
			int index_a = ft_get_perfect_index_a(&perfect_stack, stack_master);
			// if (index_a != -1)
				// printf("TIMES B: %d A: %d\n", times_b, index_to_times(index_a, stack_master->a->top));
			if (index_a != -1 && index_to_times(index_a, stack_master->a->top) < times_b)
			{
				// int times_a = index_to_times(index_a, stack_master->a->top);
				jump_to_index(stack_master, index_a, 0);
				ft_sort_and_print(stack_master, "pb");
				// printf("GOOD ft_get_perfect_index_a eco %d times\n", times_b - times_a);
			} 
			else
			{
				jump_to_index(stack_master, index_b, 1);
				ft_sort_and_print(stack_master, "pb");
				//printf("KO A %d: TIME B %d\n", stack_master->a->top, time);
			}
			
			//printf("DEBUG index %d\n", inde);
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
		ft_free_perfect_stack(perfect_stack);
		perfect_stack = ft_get_perfect_stack(stack_master);
		max_instruction++;
		if (stack_master->b->top > 1 && is_bad_index_only_b(stack_master) == -1)
		{
			ft_error("Stack B is not sorted");
			// ft_print_master_stack(stack_master);
		}
	}
	ft_free_perfect_stack(perfect_stack);
}
