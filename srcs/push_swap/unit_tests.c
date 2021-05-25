/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 02:34:45 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 19:03:43 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	unit_tests(t_stack_master *stack_master)
{
	t_stack_master	*stack_master2;

	stack_master2 = ft_duplicate_stack_master(stack_master);
	stack_master2->is_instruction = 1;
	stack_master2->is_hiding_default_output = 1;
	ft_auto_sort(stack_master2);
	ft_stack_master_free(stack_master2);
}

void	ft_test_random(int nb)
{
	int	*nbs;

	nbs = ft_random_integers(nb, nb);
	ft_test_numbers(nbs, nb);
}

void	ft_test_numbers(int *nbs, int size)
{
	t_stack_master	*stack_master;

	stack_master = ft_initialize_stack_master();
	ft_create_stack_master(stack_master, size);
	printf("Test for %d numbers >\n", size);
	while (size)
		ft_stack_add(stack_master->a, nbs[--size]);
	unit_tests(stack_master);
	free(nbs);
	ft_stack_master_free(stack_master);
}

void	ft_test_all(void)
{
	int	*nbs;
	int	nb;

	nb = 3;
	nbs = malloc(nb * sizeof(int));
	nbs[0] = 2;
	nbs[1] = 1;
	nbs[2] = 0;
	printf("\n\nSIMPLE VERSION 1 > ");
	ft_test_numbers(nbs, nb);
	nb = 5;
	nbs = malloc(nb * sizeof(int));
	nbs[0] = 1;
	nbs[1] = 5;
	nbs[2] = 2;
	nbs[3] = 4;
	nbs[4] = 3;
	printf("\n\nSIMPLE VERSION 2 > ");
	ft_test_numbers(nbs, nb);
	printf("\n\nSIMPLE VERSION 3 > ");
	ft_test_random(5);
	printf("\n\nMIDDLE VERSION > ");
	ft_test_random(100);
	printf("\n\nADVANCED VERSION > ");
	ft_test_random(500);
}

void	ft_test_args(int argc, char **argv)
{
	int	*i;

	if (argc >= 3)
	{
		i = ft_atoi_utimate(argv[2]);
		if (i == NULL)
			ft_error("Argument n°3 need to be an int");
		else
			ft_test_random(*i);
	}
	else
		ft_test_all();
}
