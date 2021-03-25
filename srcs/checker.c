/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:10:35 by ksam              #+#    #+#             */
/*   Updated: 2021/03/25 16:34:15 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libft/libft.h"

int		*transform_argument_to_array(int argc, char**argv)
{
	int		index;
	int		res;
	int		*array;
	int		i;

	index = 1;
	i = 0;
	array = malloc(sizeof(int) * (argc - 2));
	while (index < argc)
	{
		res = ft_atoi(argv[index]);
		if (res)
		{
			array[i] = res;
			i++;
		}
		else
		{
			printf("Error\n");
			exit (0);
		}
		index++;
	}
	
	return (array);
}

int		main(int argc, char **argv)
{
	int *test;
	
	if (argc > 1)
	{
		test = transform_argument_to_array(argc, argv);
		int i = 0;
		while (test[i])
		{
			printf("Je print : %d\n", test[i]);
			i++;
		}
	}
	return (0);
}