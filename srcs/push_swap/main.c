/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/05/25 12:32:40 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_master	*stack_master;

	if (argc <= 1)
		ft_error("You need to add int in argument to sort it.\n-v = verbose, "
			"-c last action colored, -h hide default output,\n"
			"-a <1 or 2 or 3 or 4 or 5> algo version, -i show count of "
			"instructions.\nOR -r <stack_size> without ints");
	else if (!ft_strncmp(argv[1], "-r", 3))
	{
		ft_test_args(argc, argv);
		return (EXIT_SUCCESS);
	}
	stack_master = ft_args_to_stack_master(argv, argc - 1);
	ft_auto_sort(stack_master);
	ft_stack_master_free(stack_master);
	return (EXIT_SUCCESS);
}
