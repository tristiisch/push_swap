/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:46:49 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:36:48 by ksam             ###   ########lyon.fr   */
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
	stack_master->is_hiding_default_output = 0;
	return (stack_master);
}

void	ft_stack_master_free(t_stack_master *stack_master)
{
	ft_stack_free_stack(stack_master->a);
	ft_stack_free_stack(stack_master->b);
	free(stack_master);
}

t_stack_master	*ft_duplicate_stack_master(t_stack_master *stack_master)
{
	t_stack_master	*new_stack_master;
	int				i;

	new_stack_master = ft_initialize_stack_master();
	new_stack_master->a = ft_stack_create(stack_master->a->capacity);
	i = 0;
	while (i <= stack_master->a->top)
		ft_stack_add(new_stack_master->a, stack_master->a->array[i++]);
	new_stack_master->b = ft_stack_create(stack_master->b->capacity);
	i = 0;
	while (i <= stack_master->b->top)
		ft_stack_add(new_stack_master->b, stack_master->b->array[i++]);
	return (new_stack_master);
}

void	ft_create_stack_master(t_stack_master *stack_master, int max_stack_size)
{
	stack_master->a = ft_stack_create(max_stack_size);
	stack_master->b = ft_stack_create(max_stack_size);
}
