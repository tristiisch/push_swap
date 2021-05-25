/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:18:39 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:38:09 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sort2(t_stack_master *stack_master, char *operator)
{
	int	i;

	if (ft_strncmp(operator, "sb", 2) == 0)
		return (ft_swap(stack_master->b));
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
		return (ft_rotate(stack_master->b));
	}
	else
	{
		dprintf(2, "ERROR > Unknown operator '%s'.\n", operator);
		return (-2);
	}
}

/** Execute operator one by one for stacks
 * @param operator rra rrb rrr sa sb ss pa pb ra rb rr
 * @return 0 for usless operator, 1 for succes, -1 for null t_stack,
 * -2 for unknown @param operator
 */	
int	ft_sort(t_stack_master *stack_master, char *operator)
{
	int	i;

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
		return (ft_reverse_rotate(stack_master->b));
	}
	else if (ft_strncmp(operator, "sa", 2) == 0)
		return (ft_swap(stack_master->a));
	else if (ft_strncmp(operator, "ss", 2) == 0)
	{
		i = ft_swap(stack_master->a);
		if (i <= 0)
			return (i);
		return (ft_swap(stack_master->b));
	}
	return (ft_sort2(stack_master, operator));
}

int	ft_sort_and_print(t_stack_master *stack_master, char *operator)
{
	int	i;

	i = ft_sort(stack_master, operator);
	if (i == 0)
		dprintf(2, "ERROR operator %s failed.\n", operator);
	else if (i < 0)
	{
		if (i == -1)
			dprintf(2, "ERROR > Stack Empty '%s'.\n", operator);
		else if (i == -2)
			dprintf(2, "ERROR > Unknown operator '%s'.\n", operator);
	}
	else
	{
		if (stack_master->is_colored && ft_is_correct(stack_master))
			printf("\033[32m%s\033[0m\n", operator);
		else if (!stack_master->is_hiding_default_output)
			printf("%s\n", operator);
		if (stack_master->is_verbose)
			ft_print_master_stack(stack_master);
		return (i);
	}
	ft_stack_master_free(stack_master);
	exit(EXIT_FAILURE);
}
