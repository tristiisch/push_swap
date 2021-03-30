/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 02:56:39 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(void)
{
	//int	a[]	= {2, 1, 3, 6, 5, 8};
	//int	b[]	= {42, 80};
	t_stack_master stack_master;
	t_stack	*stack;
	
	stack = malloc(sizeof(t_stack) * 5);
	ft_init_stack_master(&stack_master);
	stack_master.a = stack;
	
	ft_init_stack(stack);
	stack->i = 2;
	stack = stack->next;
	ft_init_stack(stack);
	//stack->i = 1;
	//stack->next = malloc(sizeof(t_stack));
	//ft_init_stack(stack);
	//stack = stack->next;
	/*stack->next->i = 1;
	stack = stack->next;
	stack->i = 3;
	stack = stack->next;
	stack->i = 6;
	stack = stack->next;
	stack->i = 5;
	stack = stack->next;
	stack->i = 8;*/
	ft_print_master_stack(&stack_master);


	
	//ft_print_master_stack(&stack_master);
	//ft_swap(&stack_master.a);
	//ft_print_master_stack(&stack_master);
	//ft_push_a_to_b(&stack_master);
	//ft_push(&stack_master, 0);
	//ft_push(&stack_master, 1);
	//ft_print_master_stack(&stack_master);
	//ft_rotate(&stack_master.a);
	//ft_print_master_stack(&stack_master);
	//ft_reverse_rotate(&stack_master.a);
	
	//test_sort(&stack_master);
	//printf("SIZE %ld = %ld\n", sizeof(a) / sizeof(int), sizeof(b) / sizeof(int));
	return (0);
}
