/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/04/12 16:06:38 by tglory           ###   ########lyon.fr   */
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

	if (argc <= 1)
	{
		printf("You need to add int in argument to sort it.\n-v = verbose, -c last action colored.\n");
		exit (EXIT_SUCCESS);
	}
	else if (argc >= 2 && !ft_strncmp(argv[1], "-ex", 3))
	{
		test_exemple();
		return (0);
	}
	stack_master = malloc(sizeof(t_stack_master));
	stack_master->instruction = 0;
	stack_master->is_verbose = 0;
	stack_master->is_colored = 0;
	stack_master->a = ft_stack_create(argc - 1);
	stack_master->b = ft_stack_create(argc - 1);
	index = 1;
	while (argv[index])
	{
		if (!ft_strncmp(argv[index], "-v", 2))
			stack_master->is_verbose = 1;
		else if (!ft_strncmp(argv[index], "-c", 2))
			stack_master->is_colored = 1;
		else
			ft_add(stack_master->a, argv[index]);
		index++;
	}
	ft_print_master_stack(stack_master);
	test_sort(stack_master);
	printf("instructions > %d\n", stack_master->instruction);
	return (0);
}
