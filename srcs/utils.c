/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:34:47 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 02:52:14 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack_master(t_stack_master *stack_master)
{
	stack_master->a = NULL;
	stack_master->b = NULL;
}

void	ft_init_stack(t_stack *stack)
{
	stack->i = -42;
	stack->next = NULL;
}

void	ft_print_stack(t_stack *stack)
{
	t_stack *iterable;

	iterable = stack;
	printf("pile : ");
	while (iterable != NULL)
	{
		printf("%d ", iterable->i);
		iterable = stack->next;
	}
	printf("\n");
}

void	ft_print_master_stack(t_stack_master *stack_master)
{
	printf("A ");
	ft_print_stack(stack_master->a);
	printf("B ");
	ft_print_stack(stack_master->b);
}
