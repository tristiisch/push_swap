/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:35:39 by ksam              #+#    #+#             */
/*   Updated: 2021/05/13 16:22:34 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	exec_instructions(t_stack_master *t_stack_master, t_master *manager)
{
	manager->current = manager->first;
	while (manager->current)
	{
		ft_sort(t_stack_master, manager->current->val);
		manager->current = manager->current->next;
	}
	if (ft_is_correct(t_stack_master) == 1)
		printf("OK!\n");
	else
		printf("KO !\n");
}

int	main(int argc, char **argv)
{
	int				*number_to_order;
	char			*buffer;
	char			**instructions;
	t_master		*manager;
	t_stack_master	*stack_master;

	manager = manager_initializor();
	instructions = instructions_initializor();
	if (argc > 1)
	{
		number_to_order = transform_argument_to_array(argc, argv);
		if (number_to_order)
		{
			while (get_next_line(0, &buffer) > 0)
				data_backpusher(manager, buffer);
			free(buffer);
			check_instructions(manager, instructions);
			stack_master = fill_astack_with_arg(number_to_order, argc - 1);
			exec_instructions(stack_master, manager);
			free_all(number_to_order, stack_master);
		}
	}
	free_manager(manager, instructions);
	return (0);
}
