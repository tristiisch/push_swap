/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 04:47:07 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:33:15 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdlib.h>
#include <time.h>

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
	nbs = ft_random_integers(nb, max_nb);
	i = nb - 1;
	while (i >= 0)
	{
		printf("%d ", nbs[i]);
		i--;
	}
	printf("\n");
	free(nbs);
}
