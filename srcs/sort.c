/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/05/13 17:54:34 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/** Sort automatically stacks
 * 
 */
void	ft_auto_sort(t_stack_master *stack_master)
{
	t_perfect_stack perfect_stack;
	int	top;
	int	max_instruction; // TODO remove max instruction

	if (stack_master->is_verbose == 1)
		ft_print_master_stack(stack_master);
	perfect_stack = ft_get_perfect_stack(stack_master);
	max_instruction = 0;
	while (!(ft_is_correct(stack_master))/* && max_instruction < 100*/)
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
		else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] == stack_master->a->top)
			ft_sort_and_print(stack_master, "pb");
		else if (perfect_stack.size_a == 2 && ft_can_be_revert(stack_master->a, perfect_stack.perfect_array_a))
			ft_sort_and_print(stack_master, "sa");
		else if (stack_master->algo_version >= 3 && perfect_stack.size_a > 1 && perfect_stack.perfect_array_a[0][0] == stack_master->a->top)
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

/** Execute operator one by one for stacks
 * @param operator rra rrb rrr sa sb ss pa pb ra rb rr
 * @return 0 for usless operator, 1 for succes, -1 for null t_stack, -2 for unknown @param operator
 */	
int	ft_sort(t_stack_master *stack_master, char *operator)
{
	int i;

	stack_master->instructions++;
	if (ft_strncmp(operator, "rra", 3) == 0)
		return (ft_reverse_rotate(stack_master->a));
	else if (ft_strncmp(operator, "rrb", 3) == 0)
		return (ft_reverse_rotate(stack_master->b));
	else if (ft_strncmp(operator, "rrr", 3) == 0)
	{
		i = ft_reverse_rotate(stack_master->a);
		if (i <= 0)
			return (i);
		stack_master->instructions++;
		return (ft_reverse_rotate(stack_master->b));
	}
	else if (ft_strncmp(operator, "sa", 2) == 0)
		return (ft_swap(stack_master->a));
	else if (ft_strncmp(operator, "sb", 2) == 0)
		return (ft_swap(stack_master->b));
	else if (ft_strncmp(operator, "ss", 2) == 0)
	{
		i = ft_swap(stack_master->a);
		if (i <= 0)
			return (i);
		stack_master->instructions++;
		return (ft_swap(stack_master->b));
	}
	else if (ft_strncmp(operator, "pa", 2) == 0)
		return (ft_push(stack_master, 0));
	else if (ft_strncmp(operator, "pb", 2) == 0)
		return (ft_push(stack_master, 1));
	else if (ft_strncmp(operator, "ra", 2) == 0)
		return (ft_rotate(stack_master->a));
	else if (ft_strncmp(operator, "rb", 2) == 0)
		return (ft_rotate(stack_master->b));
	else if (ft_strncmp(operator, "rr", 2) == 0)
	{
		i = ft_rotate(stack_master->a);
		if (i <= 0)
			return (i);
		stack_master->instructions++;
		return (ft_rotate(stack_master->b));
	}
	else
	{
		printf("ERROR > Unknown operator '%s'.\n", operator);
		return (-2);
	}
}

int	ft_sort_and_print(t_stack_master *stack_master, char *operator)
{
	int i;

	i = ft_sort(stack_master, operator);
	
	if (i == 0)
		printf("ERROR operator %s failed.\n", operator);
	else if (i < 0) {
		if (i == -1)
			printf("ERROR > Stack Empty '%s'.\n", operator);
		else if (i == -2)
			printf("ERROR > Unknown operator '%s'.\n", operator);
	}
	else {
		if (stack_master->is_colored && ft_is_correct(stack_master))
			printf("\033[32m%s\033[0m\n", operator);
		else if (!stack_master->is_hiding_default_output)
			printf("%s\n", operator);
		if (stack_master->is_verbose)
			ft_print_master_stack(stack_master);
		return (i);
	}
	exit(EXIT_FAILURE);
}
