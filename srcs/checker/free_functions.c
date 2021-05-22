/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:02:41 by ksam              #+#    #+#             */
/*   Updated: 2021/05/22 22:04:45 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_all(int *number_to_order, t_stack_master *stack_master, char ** instructions)
{
	free(number_to_order);
	ft_stack_free_stack(stack_master->a);
	ft_stack_free_stack(stack_master->b);
	if (stack_master)
		free(stack_master);
	if (instructions)
		free(instructions);
}

void	free_manager(t_master *manager)
{
	while (manager->count)
		data_eraser(manager, manager->first, 1);
	if (manager)
		free(manager);
}
