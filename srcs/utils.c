/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:34:47 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 06:03:49 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_init_stack_master(t_stack_master *stack_master)
{
	stack_master->a = NULL;
	stack_master->b = NULL;
}

void	ft_print_stack(t_stack *stack)
{
	int i;

	i = 0;
	printf("pile : ");
	if (stack != NULL)
	{
		if (ft_stack_is_empty(stack))
			printf("EMPTY");
		else
		{
			printf("size = %d ", stack->top + 1);
			while (i <= stack->top)
			{
				printf("[%d] = %d, ", i, stack->array[i]);
				i++;
			}
		}
	}
	else
		printf("NULL");
	printf("\n");
}

void	ft_print_master_stack(t_stack_master *stack_master)
{
	printf("A ");
	ft_print_stack(stack_master->a);
	printf("B ");
	ft_print_stack(stack_master->b);
}
