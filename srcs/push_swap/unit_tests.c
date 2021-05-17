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

void	unit_tests(t_stack_master *stack_master)
{
	int i;
	int	max_algo;
	t_stack_master *stack_master2;

	i = 1;
	max_algo = 5;
	stack_master2 = ft_duplicate_stack_master(stack_master);
	while(i <= max_algo)
	{
		stack_master2->is_instruction = 1;
		stack_master2->is_hiding_default_output = 1;
		stack_master2->algo_version = i;
		//stack_master2->is_verbose = 1;
		/*if (stack_master2->a->capacity < 10 &&  i == 5)
		{
			stack_master2->is_verbose = 1;
			stack_master2->is_hiding_default_output = 0;
		}*/
		ft_auto_sort(stack_master2);
		if (i++ <= max_algo) {
			ft_stack_master_free(stack_master2);
			stack_master2 = ft_duplicate_stack_master(stack_master);
		}
	}
	ft_stack_master_free(stack_master2);
}

void	ft_test_all_algos_numbers(int *nbs, int size)
{
	t_stack_master	*stack_master;

	stack_master = ft_initialize_stack_master();
	ft_create_stack_master(stack_master, size);
	printf("Test all algo for %d numbers >\n", size);
	while (size)
		ft_stack_add(stack_master->a, nbs[size--]);
	unit_tests(stack_master);
	free(nbs);
}

void	ft_test_all_algos_random(int nb, int is_big_numbers)
{
	int				*nbs;

	if (is_big_numbers == 1)
		is_big_numbers = nb;
	nbs = ft_random_integers(nb, is_big_numbers);
	ft_test_all_algos_numbers(nbs, nb);
}

void	ft_test_all(int is_big_numbers)
{
	int	*nbs;
	int	nb;

	nb = 3;
	nbs = malloc(nb * sizeof(int));
	nbs[0] = 2;
	nbs[1] = 1;
	nbs[2] = 0;
	printf("\n\nSIMPLE VERSION 1 > ");
	ft_test_all_algos_numbers(nbs, nb);
	nb = 5;
	nbs = malloc(nb * sizeof(int));
	nbs[0] = 1;
	nbs[1] = 5;
	nbs[2] = 2;
	nbs[3] = 4;
	nbs[4] = 3;
	printf("\n\nSIMPLE VERSION 2 > ");
	ft_test_all_algos_numbers(nbs, nb);
	printf("\n\nSIMPLE VERSION 3 > ");
	ft_test_all_algos_random(5, is_big_numbers);
	printf("\n\nMIDDLE VERSION > ");
	ft_test_all_algos_random(100, is_big_numbers);
	printf("\n\nADVANCED VERSION > ");
	ft_test_all_algos_random(500, is_big_numbers);
}

void	ft_test_all_algos(t_stack_master *stack_master, int argc, char **argv)
{
	int i;
	int	max_algo;
	t_stack_master	*best_stack_master;

	best_stack_master = NULL;
	i = 1;
	max_algo = 5;
	while(i <= max_algo)
	{
		stack_master->is_hiding_default_output = 1;
		stack_master->is_instruction = 1;
		stack_master->is_verbose = 0;
		stack_master->algo_version = i;
		ft_auto_sort(stack_master);
		if (best_stack_master == NULL || best_stack_master->instructions > stack_master->instructions)
			best_stack_master = stack_master;
		else
			ft_stack_master_free(stack_master);
		if (i++ <= max_algo)
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
