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

int	*get_num(char *arg)
{
	int	*nb_atoi;

	nb_atoi = ft_atoi_utimate(arg);
	if (nb_atoi == NULL)
	{
		ft_error("one of arg is not a number");
	}
	return (nb_atoi);
}

int	*ran_number_assignation(int nb, int max_nb)
{
	int	i;
	int	random;
	int	*nbs;

	i = 0;
	nbs = malloc(nb * sizeof(int));
	srand(time(NULL));
	while (i < nb)
	{
		random = -1;
		while (random == -1 || ft_contain_int(nbs, random, nb) == 1)
		{
			if (max_nb <= 0)
				random = rand();
			else
				random = rand() % (max_nb + 1);
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
	int	max_nb;

	if (argc <= 1)
		ft_error("arg 1 is not set");
	nb = *get_num(argv[1]);
	if (argc >= 3)
		max_nb = *get_num(argv[2]);
	else
		max_nb = nb;
	nbs = ran_number_assignation(nb, max_nb);
	i = nb - 1;
	while (i >= 0)
	{
		printf("%d ", nbs[i]);
		i--;
	}
	printf("\n");
	free(nbs);
}
