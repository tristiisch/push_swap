/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 16:57:09 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(void)
{
	int	a[]	= {9, 5, 4, 3};
	int	b[]	= {5};
	t_stack_master	stack_master;

	stack_master.a.array = a;
	stack_master.b.array = b;
	stack_master.a.length = sizeof(a) / sizeof(int);
	stack_master.b.length = sizeof(b) / sizeof(int);
	ft_print_master_stack(&stack_master);
	ft_swap(&stack_master.a);
	ft_print_master_stack(&stack_master);
	ft_push(&stack_master, 0);
	ft_print_master_stack(&stack_master);
	return (0);
}
