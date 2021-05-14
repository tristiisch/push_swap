/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:34:45 by tglory            #+#    #+#             */
/*   Updated: 2021/05/14 02:34:45 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	test_exemple(void)
{
	t_stack_master	*stack_master;

	stack_master = ft_initialize_stack_master();
	ft_create_stack_master(stack_master, 6);
	stack_master->is_verbose = 1;
	ft_stack_add(stack_master->a, 8);
	ft_stack_add(stack_master->a, 5);
	ft_stack_add(stack_master->a, 6);
	ft_stack_add(stack_master->a, 3);
	ft_stack_add(stack_master->a, 1);
	ft_stack_add(stack_master->a, 2);
	ft_auto_sort(stack_master);
	free(stack_master);
}

void	test_all_algo(t_stack_master *stack_master, int argc, char **argv)
{
	int i;
	t_stack_master	*best_stack_master;

	best_stack_master = NULL;
	i = 1;
	while(i <= 4)
	{
		stack_master->is_hiding_default_output = 1;
		stack_master->is_instruction = 1;
		stack_master->is_verbose = 0;
		stack_master->algo_version = i;
		if (stack_master->algo_version == 5)
			stack_master->is_verbose = 1;
		ft_auto_sort(stack_master);
		if (best_stack_master == NULL || best_stack_master->instructions > stack_master->instructions)
			best_stack_master = stack_master;
		else
			ft_stack_master_free(stack_master);
		if (i++ != 4)
			stack_master = ft_args_to_stack_master(argv, argc - 1);
	}
	if (best_stack_master == NULL)
		ft_error("Aucune données concernant le meilleur algo.");
	else
	{
		printf("\033[32mLe meilleur algo pour %d chiffres est le n°%d : %d\033[0m\n", best_stack_master->a->capacity, best_stack_master->algo_version, best_stack_master->instructions);
		ft_stack_master_free(best_stack_master);
	}
}
