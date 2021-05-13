/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/05/13 18:23:20 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	test_exemple(void)
{
	t_stack_master	*stack_master;

	stack_master = ft_initialize_stack_master();
	ft_create_stack_master(stack_master, 6);
	stack_master->is_verbose = 1;
	ft_stack_add(stack_master->a, 8);
	ft_stack_add(stack_master->a, 5);
	ft_stack_add(stack_master->a, 6);
	ft_stack_add(stack_master->a, 3);
	ft_stack_add(stack_master->a, 1);
	ft_stack_add(stack_master->a, 2);
	ft_auto_sort(stack_master);
	free(stack_master);
}

int	main(int argc, char **argv)
{
	t_stack_master	*stack_master;

	if (argc <= 1)
		ft_error("You need to add int in argument to sort it.\n-v = verbose," \
		" -c last action colored, -h hide default output," \
		" -a <int> algo version");
	else if (argc >= 2 && !ft_strncmp(argv[1], "-ex", 3))
	{
		test_exemple();
		return (EXIT_SUCCESS);
	}
	stack_master = ft_args_to_stack_master(argv, argc - 1);
	if (stack_master->algo_version == 0)
		ft_auto_sort2(stack_master);
	else
		ft_auto_sort(stack_master);
	return (EXIT_SUCCESS);
}
