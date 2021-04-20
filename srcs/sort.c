/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/04/20 06:47:25 by tglory           ###   ########lyon.fr   */
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
	int	i;

	perfect_stack = ft_get_perfect_stack(stack_master);
	i = 0;
	while (!(ft_is_correct(stack_master)) && i < 25)
	{
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
		/* Pas fini. Test pour voir si la stack est dans l'ordre mais qu'il faut juste la déplacer avec ra ou rra
		Usless, c'est le comportement par default --'
		else if (is_bad_index_only(stack_master))
		{
			int test = is_bad_index_only(stack_master);
			printf("JUMP TO INDEX %d\n", test);
			jump_to_index(stack_master, test, 0);
		}*/
		else if (perfect_stack.size_a > 0 && perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] == stack_master->a->top)
			ft_sort(stack_master, "pb");
		else if (ft_can_be_revert(stack_master->a, perfect_stack.perfect_array_a))
			ft_sort(stack_master, "sa");
		/* Essaie d'utiliser sb. Résultat : Pas opti
		else if (perfect_stack.size_a > 1 && perfect_stack.perfect_array_a[perfect_stack.size_a - 2][0] == stack_master->a->top)
		{
			printf("NEW ONE %d\n", stack_master->a->top);
			ft_sort(stack_master, "pb");
			//perfect_stack = ft_get_perfect_stack(stack_master);
			while (perfect_stack.perfect_array_a[perfect_stack.size_a - 1][1] != stack_master->a->array[stack_master->a->top])
			{
				if (perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0] > stack_master->a->top / 2)
					ft_sort(stack_master, "ra");
				else
					ft_sort(stack_master, "rra");
				printf("PERFECT STACK %d - %d\n", perfect_stack.perfect_array_a[perfect_stack.size_a - 1][0], stack_master->a->top);
			}
			ft_sort(stack_master, "pb");
			ft_sort(stack_master, "sb");
		}*/
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

/** Execute operator one by one for stacks
 * @param operator rra rrb rrr sa sb ss pa pb ra rb rr
 */
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
