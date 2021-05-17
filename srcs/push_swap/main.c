/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/05/17 03:21:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_test_args(int argc, char **argv)
{
	int	*i;
	int	*is_big_numbers;

	if (argc >= 3)
	{
		i = ft_atoi_utimate(argv[2]);
		if (i == NULL)
			i = 0;
	}
	else
	{
		ft_test_all(0);
		return ;
	}
	if (argc >= 4)
	{
		is_big_numbers = ft_atoi_utimate(argv[3]);
		if (is_big_numbers == NULL)
			ft_error("Argument -r <numbers> [max_int] -> [max_int] need to be a int.");
		ft_test_all_algos_random(*i, *is_big_numbers);
	}
	else
		ft_test_all_algos_random(*i, 0);
}

int	main(int argc, char **argv)
{
	t_stack_master	*stack_master;

	if (argc <= 1)
		ft_error("You need to add int in argument to sort it.\n-v = verbose,"
				 " -c last action colored, -h hide default output,"
				 " -a <1 or 2 or 3 or 4 or 5> algo version, -i show count of instructions,"
				 " -t test all algo.\nOR -r [size_random_int] [1 or 0], 1 or 0 is for big random number or not");
	else if (argc >= 2 && !ft_strncmp(argv[1], "-r", 3))
	{
		ft_test_args(argc, argv);
		return (EXIT_SUCCESS);
	}
	stack_master = ft_args_to_stack_master(argv, argc - 1);
	if (stack_master->algo_version == 0)
	{
		ft_test_all_algos(stack_master, argc, argv);
		return (EXIT_SUCCESS);
	}
	else
		ft_auto_sort(stack_master);
	ft_stack_master_free(stack_master);
	return (EXIT_SUCCESS);
}
