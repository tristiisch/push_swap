/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/26 14:03:25 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(void)
{
	int	a[]	= {2, 1, 3, 6, 5, 8};
	int	b[]	= {};
	t_stack_master	stack_master;

	stack_master.a.array = a;
	stack_master.b.array = b;
	stack_master.a.length = sizeof(a) / sizeof(int);
	stack_master.b.length = sizeof(b) / sizeof(int);
	ft_print_master_stack(&stack_master);
	//ft_swap(&stack_master.a);
	//ft_print_master_stack(&stack_master);
	//ft_push(&stack_master, 0);
	//ft_print_master_stack(&stack_master);
	ft_rotate(&stack_master.a);
	ft_print_master_stack(&stack_master);
	ft_reverse_rotate(&stack_master.a);
	ft_print_master_stack(&stack_master);
	return (0);
}
