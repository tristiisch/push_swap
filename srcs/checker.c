/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:10:35 by ksam              #+#    #+#             */
/*   Updated: 2021/03/26 14:38:23 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		*transform_argument_to_array(int argc, char**argv)
{
	int		index;
	int		res;
	int		*array;

	index = 1;
	array = malloc(sizeof(int) * (argc - 2)); // TODO free
	while (index < argc)
	{
		res = ft_atoi(argv[index]);
		if (res)
			array[index - 1] = res;
		else
		{
			printf("Error\n");
			exit (0);
		}
		index++;
	}
	
	return (array);
}
