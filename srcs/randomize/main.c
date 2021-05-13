/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 04:47:07 by tglory            #+#    #+#             */
/*   Updated: 2021/05/11 04:47:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>
#include <time.h>

int	ft_contain_int(int *nbs, int i, int size)
{
	while (size >= 0)
	{
		if (nbs[--size] == i)
			return (1);
	}
	return (0);
}

int	*get_num(char **argv)
{
	int	*nbs;
	int	*nb_atoi;
	int	nb;
	int	random;
	int	i;

	nb_atoi = ft_atoi_utimate(argv[1]);
	if (nb_atoi == NULL)
	{
		ft_error("arg 1 is not a number");
	}
	return (nb_atoi);
}

int	*ran_number_assignation(int nb)
{
	int	i;
	int	random;
	int	*nbs;

	i = 0;
	nbs = ft_calloc(nb, sizeof(int));
	srand(time(NULL));
	while (i < nb)
	{
		random = -1;
		while (random == -1 || ft_contain_int(nbs, random, nb) == 1)
		{
			random = rand();
		}
		nbs[i] = random;
		i++;
	}
	return (nbs);
}

int	main(int argc, char **argv)
{
	int	*nbs;
	int	nb;
	int	i;

	if (argc <= 1)
		ft_error("arg 1 is not set");
	nb = *get_num(argv);
	nbs = ran_number_assignation(nb);
	i = nb - 1;
	while (i >= 0)
	{
		printf("%d ", nbs[i]);
		i--;
	}
	printf("\n");
	free(nbs);
}
