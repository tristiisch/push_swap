/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_arg_to_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 01:36:16 by ksam              #+#    #+#             */
/*   Updated: 2021/05/13 17:57:12 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	arg_verification(int res, int *array, int current)
{
	int	i;

	if (res >= 0)
	{
		i = 0;
		while (i <= current - 2)
		{
			if (array[i] == res)
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

void	is_arg_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			i++;
		else
		{
			printf("Error \n");
			exit (0);
		}
	}
}

int	*transform_argument_to_array(int argc, char**argv)
{
	int		index;
	int		res;
	int		*array;

	index = 1;
	array = malloc(sizeof(int) * (argc - 1));
	while (index < argc)
	{
		is_arg_digit(argv[index]);
		res = ft_atoi(argv[index]);
		if (arg_verification(res, array, index) == 1)
			array[index - 1] = res;
		else
		{
			printf("Error \n");
			exit (0);
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
