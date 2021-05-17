/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:24:59 by tglory            #+#    #+#             */
/*   Updated: 2021/05/17 00:24:59 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
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

int	*ft_random_integers(int nb, int max_nb)
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
		nbs[i++] = random;
	}
	return (nbs);
}
