/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/04/12 15:52:37 by tglory           ###   ########lyon.fr   */
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
	test_sort(stack_master);
	printf("instructions > %d\n", stack_master->instruction);
}

int	main(int argc, char **argv)
{
	t_stack_master	*stack_master;
	int				index;

	if (argc >= 2 && !ft_strncmp(argv[1], "-ex", 3))
	{
		test_exemple();
		return (0);
	}
	stack_master = malloc(sizeof(t_stack_master));
	stack_master->a = ft_stack_create(argc - 1);
	stack_master->b = ft_stack_create(argc - 1);
	index = 1;
	while (argv[index])
		ft_add(stack_master->a, argv[index++]);
	stack_master->instruction = 0;
	ft_print_master_stack(stack_master);
	test_sort(stack_master);
	printf("instructions > %d\n", stack_master->instruction);
	return (0);
}
