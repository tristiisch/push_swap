/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/04/02 01:33:39 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	test_exemple(void)
{
	t_stack_master	*stack_master;
	
	stack_master = malloc(sizeof(t_stack_master));
	stack_master->a = ft_stack_create(6);
	stack_master->b = ft_stack_create(6);
	ft_stack_add(stack_master->a, 8);
	ft_stack_add(stack_master->a, 5);
	ft_stack_add(stack_master->a, 6);
	ft_stack_add(stack_master->a, 3);
	ft_stack_add(stack_master->a, 1);
	ft_stack_add(stack_master->a, 2);
	sort(stack_master, "sa");
	sort(stack_master, "pb");
	sort(stack_master, "pb");
	sort(stack_master, "pb");
	sort(stack_master, "rr");
	sort(stack_master, "rrr");
	sort(stack_master, "sa");
	sort(stack_master, "pa");
	sort(stack_master, "pa");
	sort(stack_master, "pa");
	printf("instructions > %d\n", stack_master->instruction);
}

int	main(int argc, char **argv)
{
	t_stack_master	*stack_master;
	
	if (argc > 1 && !ft_strncmp(argv[1], "-ex", 3))
	{
		test_exemple();
		return (0);
	}
	// Used for debug Only
	stack_master = malloc(sizeof(t_stack_master));
	stack_master->a = ft_stack_create(6);
	stack_master->b = ft_stack_create(6);
	// -------------------
	//ft_print_master_stack(stack_master);
	ft_stack_add(stack_master->a, 8);
	ft_stack_add(stack_master->a, 5);
	ft_stack_add(stack_master->a, 6);
	ft_stack_add(stack_master->a, 3);
	ft_stack_add(stack_master->a, 1);
	ft_stack_add(stack_master->a, 2);
	//ft_stack_add(stack_b, 42);
	stack_master->instruction = 0;
	ft_print_master_stack(stack_master);
	//ft_push(&stack_master, 1);
	//ft_push(&stack_master, 0);
	//ft_swap(stack_master.b);
	//ft_reverse_rotate(stack_master.a);
	//ft_rotate(stack_master.a);
	//sort_by_biggest(stack_master, -1);
	test_sort(stack_master);
	ft_print_master_stack(stack_master);
	printf("instructions > %d\n", stack_master->instruction);
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
