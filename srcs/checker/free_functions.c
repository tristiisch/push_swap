/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:02:41 by tglory            #+#    #+#             */
/*   Updated: 2021/05/25 12:28:14 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_all(int *number_to_order, t_stack_master *stack_master)
{
	free(number_to_order);
	ft_stack_free_stack(stack_master->a);
	ft_stack_free_stack(stack_master->b);
	if (stack_master)
		free(stack_master);
}

void	free_manager(t_master *manager, char **instructions)
{
	while (manager->count)
		data_eraser(manager, manager->first, 1);
	if (manager)
		free(manager);
	if (instructions)
		free(instructions);
}
