/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/03/29 00:06:49 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	jump_to_index(t_stack *stack, int index)
{
	int length;
	int times;

	length = stack->length;
	times = length - (index + 1);
	while (times > 0)
	{
		ft_rotate(stack);// TODO Change to sort(stack_master, "pb");
		printf("rotate %d ", times);
		ft_print_stack(stack);
		times--;
	}
}

size_t	get_index_of_smallest(t_stack *stack)
{
	int index;
	size_t saved_index;
	int i;

	index = stack->length - 1;
	i = 0; // TODO remove this to support sorting 0
	while (index >= 0)
	{
		if (i > stack->array[index])
		{
			i = stack->array[index];
			saved_index = index;
		}
		index--;
	}
	return saved_index;
}

void	test_sort(t_stack_master *stack_master)
{
	int length;
	int last_index;
	int index;

	last_index = -1;
	length = (stack_master->a).length;
	while (length >= 0)
	{
		index = get_index_of_smallest(&(stack_master->a));
		if (last_index == index)
			break;
		else
		{
			jump_to_index(&(stack_master->a), index);
			sort(stack_master, "pb");
		}
		length--;
	}
}


void	check_sort(t_stack_master *stack_master)
{
	int index;

	index = (stack_master->a).length - 1;
	if ((stack_master->a).array[index] > (stack_master->a).array[index - 1])
		sort(stack_master, "sa");
	while ((stack_master->a).array[index] < (stack_master->a).array[index - 1])
	{
		sort(stack_master, "pb");
	}
	if ((stack_master->a).array[0] < (stack_master->a).array[index - 1])
	{
		
	}
}

void	sort(t_stack_master *stack_master, char *operator)
{
	if (ft_strncmp(operator, "sa", 2) == 0)
		ft_swap(&stack_master->a);
	else if (ft_strncmp(operator, "sb", 2) == 0)
		ft_swap(&stack_master->b);
	else if (ft_strncmp(operator, "ss", 2) == 0)
	{
		ft_swap(&stack_master->a);
		ft_swap(&stack_master->b);
	}
	else if (ft_strncmp(operator, "pa", 2) == 0)
		ft_push(stack_master, 0);
	else if (ft_strncmp(operator, "pb", 2) == 0)
		ft_push(stack_master, 1);
	else if (ft_strncmp(operator, "ra", 2) == 0)
		ft_rotate(&stack_master->a);
	else if (ft_strncmp(operator, "rb", 2) == 0)
		ft_rotate(&stack_master->b);
	else if (ft_strncmp(operator, "rr", 2) == 0)
	{
		ft_rotate(&stack_master->a);
		ft_rotate(&stack_master->b);
	}
	else if (ft_strncmp(operator, "rra", 3) == 0)
		ft_reverse_rotate(&stack_master->a);
	else if (ft_strncmp(operator, "rrb", 3) == 0)
		ft_reverse_rotate(&stack_master->b);
	else if (ft_strncmp(operator, "rrr", 3) == 0)
	{
		ft_reverse_rotate(&stack_master->a);
		ft_reverse_rotate(&stack_master->b);
	}
	printf("%s\n", operator);
	ft_print_master_stack(stack_master);
}
