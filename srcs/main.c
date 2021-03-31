/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 05:29:04 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	test_exemple(void)
{
	t_stack_master	stack_master;
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = ft_stack_duplicate_push(stack_a, 8);
	stack_a = ft_stack_duplicate_push(stack_a, 5);
	stack_a = ft_stack_duplicate_push(stack_a, 6);
	stack_a = ft_stack_duplicate_push(stack_a, 3);
	stack_a = ft_stack_duplicate_push(stack_a, 1);
	stack_a = ft_stack_duplicate_push(stack_a, 2);
	stack_master.a = stack_a;
	stack_master.b = stack_b;
	ft_print_master_stack(&stack_master);
	sort(&stack_master, "sa");
	sort(&stack_master, "pb");
	sort(&stack_master, "pb");
	sort(&stack_master, "pb");
	sort(&stack_master, "rr");
	sort(&stack_master, "rrr");
	sort(&stack_master, "sa");
	sort(&stack_master, "pa");
	sort(&stack_master, "pa");
	sort(&stack_master, "pa");
}

int	main(void)
{
	t_stack_master	stack_master;
	t_stack			*stack_a;
	t_stack			*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	// Used for debug Only
	stack_master.a = stack_a;
	stack_master.b = stack_b;
	// -------------------
	//ft_print_master_stack(&stack_master);
	stack_a = ft_stack_duplicate_push(stack_a, 8);
	stack_a = ft_stack_duplicate_push(stack_a, 5);
	stack_a = ft_stack_duplicate_push(stack_a, 6);
	stack_a = ft_stack_duplicate_push(stack_a, 3);
	stack_a = ft_stack_duplicate_push(stack_a, 1);
	stack_a = ft_stack_duplicate_push(stack_a, 2);
	//stack_b = ft_stack_duplicate_push(stack_b, 42);
	stack_master.a = stack_a;
	stack_master.b = stack_b;
	stack_master.instruction = 0;
	ft_print_master_stack(&stack_master);
	//ft_push(&stack_master, 1);
	//ft_push(&stack_master, 0);
	//ft_swap(stack_master.b);
	//ft_reverse_rotate(stack_master.a);
	//ft_rotate(stack_master.a);
	test_sort(&stack_master);
	printf("instructions > %d\n", stack_master.instruction); // Need fix
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
