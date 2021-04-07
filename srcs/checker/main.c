/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:35:39 by ksam              #+#    #+#             */
/*   Updated: 2021/03/26 16:05:11 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		compare_instruction(char *buffer, char *instructions)
{
	if (buffer)
	{
		if (ft_strcmp(buffer, instructions) == 0 && ft_strlen(buffer) == ft_strlen(instructions))
			return (1);
	}
	return (0);
}

void	check_instructions(t_master *manager, char **instructions)
{
	int i;


	manager->current = manager->first;
	while (manager->current)
	{
		i = 0;
		while (i <= 10)
		{
			if (compare_instruction(manager->current->val, instructions[i]) == 1)
				break;
			if (i == 10)
			{
				printf("Error instruction %s not found\n", manager->current->val);
				exit (0);
			}
			i++;
		}
		manager->current = manager->current->next;
	}
}

int		main(int argc, char **argv)
{
	int			*test;
	char		*buffer;
	char		*instructions[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr", "rra", "rrb", "rrr"};
	t_master	*manager;

	manager = manager_initializor();
	if (argc > 1)
	{
		test = transform_argument_to_array(argc, argv);
		if (test)
		{
			while (get_next_line(0, &buffer) > 0)
			{
				data_backpusher(manager, buffer);
			}
			check_instructions(manager, instructions);
		}
	}
	return (0);
}