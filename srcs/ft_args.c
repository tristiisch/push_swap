/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:48:20 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:35:31 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_args_to_stack_master2(t_stack_master	*stack_master, char *arg)
{
	if (!ft_strncmp(arg, "-c", 3))
		stack_master->is_colored = 1;
	else if (!ft_strncmp(arg, "-v", 3))
		stack_master->is_verbose = 1;
	else if (!ft_strncmp(arg, "-i", 3))
		stack_master->is_instruction = 1;
	else if (!ft_strncmp(arg, "-h", 3))
		stack_master->is_hiding_default_output = 1;
	else
		return (0);
	return (1);
}

t_stack_master	*ft_args_to_stack_master(char **argv, int max_stack_size)
{
	t_stack_master	*stack_master;
	int				i;

	stack_master = ft_initialize_stack_master();
	i = max_stack_size;
	while (i)
	{
		if (ft_args_to_stack_master2(stack_master, argv[i--]) == 1)
			max_stack_size--;
		else
			break ;
	}
	if (max_stack_size == 0)
		ft_error_master(stack_master, "You need to add integer in arguments");
	ft_create_stack_master(stack_master, max_stack_size);
	while (max_stack_size)
		ft_add(stack_master, stack_master->a, argv[max_stack_size--]);
	return (stack_master);
}
