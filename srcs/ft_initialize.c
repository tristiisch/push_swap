/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:46:49 by tglory            #+#    #+#             */
/*   Updated: 2021/05/14 10:32:22 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_master	*ft_initialize_stack_master(void)
{
	t_stack_master	*stack_master;

	stack_master = ft_calloc(1, sizeof(t_stack_master));
	if (stack_master == NULL)
		ft_error_memomy();
	stack_master->is_colored = 0;
	stack_master->is_instruction = 0;
	stack_master->instructions = 0;
	stack_master->is_verbose = 0;
	stack_master->algo_version = 1;
	stack_master->is_hiding_default_output = 0;
	return (stack_master);
}

void	ft_stack_master_free(t_stack_master *stack_master)
{
	ft_stack_free_stack(stack_master->a);
	ft_stack_free_stack(stack_master->b);
	free(stack_master);
}

void	ft_create_stack_master(t_stack_master *stack_master, int max_stack_size)
{
	stack_master->a = ft_stack_create(max_stack_size);
	stack_master->b = ft_stack_create(max_stack_size);
}

t_stack_master	*ft_args_to_stack_master(char **argv, int max_stack_size)
{
	t_stack_master	*stack_master;
	int i;

	stack_master = ft_initialize_stack_master();
	i = max_stack_size;
	while (i)
	{
		if (!ft_strncmp(argv[i], "-c", 2))
			stack_master->is_colored = 1;
		else if (!ft_strncmp(argv[i], "-v", 2))
			stack_master->is_verbose = 1;
		else if (!ft_strncmp(argv[i], "-i", 2))
			stack_master->is_instruction = 1;
		else if (!ft_strncmp(argv[i], "-h", 2))
			stack_master->is_hiding_default_output = 1;
		else if (!ft_strncmp(argv[i - 1], "-a", 2))
		{
			stack_master->algo_version =
			*ft_atoi_utimate(argv[i--]);
			max_stack_size--;
		}
		else if (!ft_strncmp(argv[i], "-t", 2))
			stack_master->algo_version = 0;
		else
			break;
		max_stack_size--;
		i--;
	}
	if (max_stack_size == 0)
		ft_error_master(stack_master, "You need to add integer in arguments");
	ft_create_stack_master(stack_master, max_stack_size);
	while (max_stack_size)
	{
		ft_add(stack_master->a, argv[max_stack_size--]);
	}
	return (stack_master);
}
