/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:10:35 by ksam              #+#    #+#             */
/*   Updated: 2021/05/07 11:07:03 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		compare_instruction(char *buffer, char *instructions)
{
	if (buffer)
	{
		if ((ft_strcmp(buffer, instructions) != 0)
							&& (ft_strlen(buffer) == ft_strlen(instructions)))
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
			if (compare_instruction(manager->current->val,
									instructions[i]) == 1)
				break;
			if (i == 10)
			{
				printf("Error instruction -%s- not found\n",
									manager->current->val);
				exit (0);
			}
			i++;
		}
		manager->current = manager->current->next;
	}
}

t_stack_master *fill_astack_with_arg(int *nb, int argc)
{
	t_stack_master	*stack_master;
	int				k;

	k = 0;
	stack_master = malloc(sizeof(t_stack_master));
	stack_master->a = ft_stack_create(argc);
	stack_master->b = ft_stack_create(argc);
	while (k < argc)
	{
		ft_stack_add(stack_master->a, nb[k]);
		k++;
	}
	return (stack_master);
}