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

void	ft_test_all_algos_random(int nb, int is_big_numbers)
{
	int	*nbs;

	if (is_big_numbers == 1)
		is_big_numbers = nb;
	nbs = ft_random_integers(nb, is_big_numbers);
	ft_test_all_algos_numbers(nbs, nb);
}

void	ft_test_args(int argc, char **argv)
{
	int	*i;
	int	*is_big_numbers;

	if (argc >= 3)
	{
		i = ft_atoi_utimate(argv[2]);
		if (i == NULL)
			i = 0;
	}
	else
	{
		ft_test_all(0);
		return ;
	}
	if (argc >= 4)
	{
		is_big_numbers = ft_atoi_utimate(argv[3]);
		if (is_big_numbers == NULL)
			ft_error("Argument -r <numbers> [max_int] ->" \
				" [max_int] need to be a int.");
		ft_test_all_algos_random(*i, *is_big_numbers);
	}
	else
		ft_test_all_algos_random(*i, 1);
}
