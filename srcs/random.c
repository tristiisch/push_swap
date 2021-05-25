/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 00:24:59 by tglory            #+#    #+#             */
/*   Updated: 2021/05/24 16:37:57 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <time.h>

int	ft_contain_int(int *nbs, int i, int size)
{
	int	i2;

	i2 = 0;
	while (i2 < size)
	{
		if (nbs[i2++] == i)
			return (1);
	}
	return (0);
}

int	*ft_random_integers(int nb, int max_nb)
{
	int	i;
	int	random;
	int	*nbs;

	if (max_nb > 0 && max_nb < nb)
		ft_error("Unable to generate random numbers, "
			"max_nb < nb");
	i = 0;
	nbs = malloc(nb * sizeof(int));
	if (nbs == NULL)
		ft_error_memomy();
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
