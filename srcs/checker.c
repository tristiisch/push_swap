/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:10:35 by ksam              #+#    #+#             */
/*   Updated: 2021/03/25 18:12:49 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*transform_argument_to_array(int argc, char**argv)
{
	int		index;
	int		res;
	int		*array;

	index = 1;
	array = malloc(sizeof(int) * (argc - 2)); // TODO free
	while (index < argc)
	{
		res = ft_atoi(argv[index]);
		if (res)
			array[index - 1] = res;
		else
		{
			printf("Error\n");
			exit (0);
		}
		index++;
	}
	
	return (array);
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
			printf("Je dois exec les instructions\n");
			manager->current = manager->first;
			while (manager->current)
			{
				printf("Je suis un maillon : %s\n", manager->current->val);
				manager->current = manager->current->next;
			}
		}
	}
	return (0);
}