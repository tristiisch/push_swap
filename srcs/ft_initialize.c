/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:46:49 by tglory            #+#    #+#             */
/*   Updated: 2021/05/13 17:29:43 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_master	*ft_initialize_stack_master(int max_stack_size)
{
	t_stack_master	*stack_master;

	stack_master = ft_calloc(1, sizeof(t_stack_master));
	if (stack_master == NULL)
		ft_error_memomy();
	stack_master->is_colored = 0;
	stack_master->is_instruction = 0;
	stack_master->instructions = 0;
	stack_master->is_verbose = 0;
	stack_master->algo_version = 3;
	stack_master->is_hiding_default_output = 0;
	stack_master->a = ft_stack_create(max_stack_size);
	stack_master->b = ft_stack_create(max_stack_size);
	return (stack_master);
}

t_stack_master	*ft_args_to_stack_master(char **argv, int max_stack_size)
{
	t_stack_master	*stack_master;

	stack_master = ft_initialize_stack_master(max_stack_size);
	while (max_stack_size)
	{
		if (!ft_strncmp(argv[max_stack_size], "-c", 2))
			stack_master->is_colored = 1;
		else if (!ft_strncmp(argv[max_stack_size], "-v", 2))
			stack_master->is_verbose = 1;
		else if (!ft_strncmp(argv[max_stack_size], "-i", 2))
			stack_master->is_instruction = 1;
		else if (!ft_strncmp(argv[max_stack_size], "-h", 2))
			stack_master->is_hiding_default_output = 1;
		else if (!ft_strncmp(argv[max_stack_size - 1], "-a", 2))
			stack_master->algo_version = \
								*ft_atoi_utimate(argv[max_stack_size--]);
		else
			ft_add(stack_master->a, argv[max_stack_size]);
		max_stack_size--;
	}
	return (stack_master);
}
