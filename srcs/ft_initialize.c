/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:46:49 by tglory            #+#    #+#             */
/*   Updated: 2021/05/19 08:27:09 by tglory           ###   ########lyon.fr   */
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
	stack_master->algo_version = 5;
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

t_stack_master	*ft_args_to_stack_master(char **argv, int max_stack_size)
{
	t_stack_master	*stack_master;
	int				i;

	stack_master = ft_initialize_stack_master();
	i = max_stack_size;
	while (i)
	{
		if (!ft_strncmp(argv[i], "-c", 3))
			stack_master->is_colored = 1;
		else if (!ft_strncmp(argv[i], "-v", 3))
			stack_master->is_verbose = 1;
		else if (!ft_strncmp(argv[i], "-i", 3))
			stack_master->is_instruction = 1;
		else if (!ft_strncmp(argv[i], "-h", 3))
			stack_master->is_hiding_default_output = 1;
		else if (!ft_strncmp(argv[i - 1], "-a", 3))
		{
			stack_master->algo_version = *ft_atoi_utimate(argv[i--]);
			max_stack_size--;
		}
		else if (!ft_strncmp(argv[i], "-t", 3))
			stack_master->algo_version = 0;
		else
			break ;
		max_stack_size--;
		i--;
	}
	if (max_stack_size == 0)
		ft_error_master(stack_master, "You need to add integer in arguments");
	ft_create_stack_master(stack_master, max_stack_size);
	while (max_stack_size)
		ft_add(stack_master->a, argv[max_stack_size--]);
	return (stack_master);
}
