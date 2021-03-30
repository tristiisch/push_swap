/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 06:10:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(void)
{
	//int	a[]	= {2, 1, 3, 6, 5, 8};
	//int	b[]	= {42, 80};
	t_stack_master stack_master;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	ft_print_master_stack(&stack_master);
	stack_a = ft_stack_duplicate_push(stack_a, 2);
	stack_a = ft_stack_duplicate_push(stack_a, 1);
	stack_a = ft_stack_duplicate_push(stack_a, 3);
	stack_a = ft_stack_duplicate_push(stack_a, 6);
	stack_a = ft_stack_duplicate_push(stack_a, 5);
	stack_a = ft_stack_duplicate_push(stack_a, 8);
	stack_b = ft_stack_duplicate_push(stack_b, 42);
	//stack = ft_stack_duplicate_push(stack, 1);
	//stack = ft_stack_duplicate_push(stack, 3);
	ft_init_stack_master(&stack_master);
	stack_master.a = stack_a;
	stack_master.b = stack_b;
	ft_print_master_stack(&stack_master);


	
	//ft_print_master_stack(&stack_master);
	//ft_swap(stack_master.a);
	//ft_print_master_stack(&stack_master);
	//ft_print_master_stack(&stack_master);
	//ft_push(&stack_master, 1);
	//ft_print_master_stack(&stack_master);
	//ft_push(&stack_master, 1);
	//ft_print_master_stack(&stack_master);
	//ft_print_master_stack(&stack_master);
	//ft_rotate(stack_master.a);
	//ft_print_master_stack(&stack_master);
	//ft_reverse_rotate(&stack_master.a);
	
	//test_sort(&stack_master);
	//printf("SIZE %ld = %ld\n", sizeof(a) / sizeof(int), sizeof(b) / sizeof(int));
	//ft_print_master_stack(&stack_master);
	return (0);
}
