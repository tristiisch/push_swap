/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:35:39 by ksam              #+#    #+#             */
/*   Updated: 2021/04/07 23:59:52 by ksam             ###   ########lyon.fr   */
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
}

int		main(int argc, char **argv)
{
	int			*number_to_order;
	char		*buffer;
	char		*instructions[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	t_master	*manager;
	t_stack_master	*stack_master;

	manager = manager_initializor();
	if (argc > 1)
	{
		number_to_order = transform_argument_to_array(argc, argv);
		if (number_to_order)
		{
			while (get_next_line(0, &buffer) > 0)
			{
				data_backpusher(manager, buffer);
			}
			check_instructions(manager, instructions);
			stack_master = fill_astack_with_arg(number_to_order, argc - 1);
			free(number_to_order);
			exec_instructions(stack_master, manager);
		}
	}
	else
		printf("Error : Need arguments\n");
	return (0);
}