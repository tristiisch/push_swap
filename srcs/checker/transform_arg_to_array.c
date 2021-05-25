/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_arg_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:36:16 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:31:38 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	arg_verification(int res, int *array, int current)
{
	int	i;

	i = 0;
	while (i <= current - 2)
	{
		if (array[i] == res)
			return (0);
		i++;
	}
	return (1);
}

int	*transform_argument_to_array(int argc, char**argv)
{
	int		index;
	int		*res;
	int		*array;

	index = 1;
	array = malloc(sizeof(int) * (argc - 1));
	while (index < argc)
	{
		res = ft_atoi_utimate(argv[index]);
		if (res == NULL)
		{
			free(array);
			ft_error("Int not in range detected");
		}
		if (arg_verification(*res, array, index) == 1)
			array[index - 1] = *res;
		else
		{
			free(array);
			ft_error("Duplicate int in stack");
		}
		index++;
	}
	return (reverse_array(array, argc));
}

int	*reverse_array(int *array, int argc)
{
	int		i;
	int		size;
	int		*ret;

	i = 0;
	size = argc - 2;
	ret = malloc(sizeof(int) * (size + 1));
	while (size >= 0)
	{
		ret[i] = array[size];
		size--;
		i++;
	}
	free(array);
	return (ret);
}
