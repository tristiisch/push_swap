/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 17:54:56 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 18:13:21 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
}
