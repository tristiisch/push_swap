/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/04/19 17:55:01 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	can_be_revert(t_stack *stack, int **perfect_array)
{
	int	i;
	int	one;
	int	one_index;
	int	two;
	int	two_index;

	if (stack->top <= 0)
		return (0);
	i = 0;
	one = stack->array[stack->top];
	two = stack->array[stack->top - 1];
	if (one < two)
		return (0);
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

void	ft_auto_sort(t_stack_master *stack_master)
{
	t_perfect_stack perfect_stack;
	int	top;
	int	i;

	perfect_stack = ft_get_perfect_stack(stack_master);
	i = 0;
	while (!(ft_is_correct(stack_master)) && i < 25)
	{
		//if (perfect_array_a != NULL && stack_master->a->top > 0 && perfect_array_a[stack_master->a->top][0] + 1 == perfect_array_a[stack_master->a->top - 1][0]
		//else if (perfect_array_b != NULL && stack_master->b->top > 0 && perfect_array_b[stack_master->b->top][0] - 1 == perfect_array_b[stack_master->b->top - 1][0])
		//	sort(stack_master, "sb"); -> usless, on a pas besoin d'inverser la stack B
		if (ft_is_updside_down(stack_master->b) && (ft_stack_is_empty(stack_master->a) || ft_is_correct_order(stack_master->a)))
		{
			top = stack_master->b->top;
			while (top >= 0)
			{
				ft_sort(stack_master, "pa");
				top--;
			}
			break;
		}
		else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] == stack_master->a->top)
			ft_sort(stack_master, "pb");
		else if (can_be_revert(stack_master->a, perfect_stack.perfect_array_a))
			ft_sort(stack_master, "sa");
		else
		{
			if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] > stack_master->a->top / 2)
				ft_sort(stack_master, "ra");
			else
				ft_sort(stack_master, "rra");
		}
		perfect_stack = ft_get_perfect_stack(stack_master);
		i++;
	}
	i = 0;
	ft_free_perfect_stack(perfect_stack);
}

void	ft_sort(t_stack_master *stack_master, char *operator)
{
	if (ft_strncmp(operator, "rra", 3) == 0)
		ft_reverse_rotate(stack_master->a);
	else if (ft_strncmp(operator, "rrb", 3) == 0)
		ft_reverse_rotate(stack_master->b);
	else if (ft_strncmp(operator, "rrr", 3) == 0)
	{
		ft_reverse_rotate(stack_master->a);
		ft_reverse_rotate(stack_master->b);
		stack_master->instruction++;
	}
	else if (ft_strncmp(operator, "sa", 2) == 0)
		ft_swap(stack_master->a);
	else if (ft_strncmp(operator, "sb", 2) == 0)
		ft_swap(stack_master->b);
	else if (ft_strncmp(operator, "ss", 2) == 0)
	{
		ft_swap(stack_master->a);
		ft_swap(stack_master->b);
		stack_master->instruction++;
	}
	else if (ft_strncmp(operator, "pa", 2) == 0)
		ft_push(stack_master, 0);
	else if (ft_strncmp(operator, "pb", 2) == 0)
		ft_push(stack_master, 1);
	else if (ft_strncmp(operator, "ra", 2) == 0)
		ft_rotate(stack_master->a);
	else if (ft_strncmp(operator, "rb", 2) == 0)
		ft_rotate(stack_master->b);
	else if (ft_strncmp(operator, "rr", 2) == 0)
	{
		ft_rotate(stack_master->a);
		ft_rotate(stack_master->b);
		stack_master->instruction++;
	}
	else
	{
		printf("ERROR > Unknown operator '%s'.\n", operator);
	}
	printf("%s\n", operator);
	stack_master->instruction++;
	if (stack_master->is_verbose)
		ft_print_master_stack(stack_master);
}
