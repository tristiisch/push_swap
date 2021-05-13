/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 18:46:49 by tglory            #+#    #+#             */
/*   Updated: 2021/05/13 18:24:24 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_master	*ft_initialize_stack_master(void)
{
	t_stack_master	*stack_master;

	stack_master = ft_calloc(1, sizeof(t_stack_master));
	if (stack_master == NULL)
		ft_error_memomy();
	stack_master->is_colored = 0;
	stack_master->is_instruction = 0;
	stack_master->instructions = 0;
	stack_master->is_verbose = 0;
	stack_master->algo_version = 3;
	stack_master->is_hiding_default_output = 0;
	return (stack_master);
}

void	ft_create_stack_master(t_stack_master *stack_master, int max_stack_size)
{
	stack_master->a = ft_stack_create(max_stack_size);
	stack_master->b = ft_stack_create(max_stack_size);
}
/*
void	add_int(t_stack_master *stack_master, char *str)
{
	int i;
	char *subbuff;

	subbuff = NULL;
	while (*str)
	{
		while (*str && !ft_isdigit(*str))
			str++;
		i = 0;
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (i == 0)
			return ;
		subbuff = malloc((i + 1) * sizeof(char));
		while (i-- > 0)
			subbuff[i] = str[i];
		subbuff[i] = '\0';
		printf("%s\n", subbuff);
		ft_add(stack_master->a, subbuff);
		while (*str && ft_isdigit(*str))
		{
			i++;
			str++;
		}
	}
}

int	count_ints(char *str)
{
	int i;
	int j;

	i = 0;
	while (*str)
	{
		while (*str && !ft_isdigit(*str))
			str++;
		j = 0;
		while (str[j] && ft_isdigit(str[j]))
			j++;
		if (j == 0)
			return (i);
		while (*str && ft_isdigit(*str))
		{
			j++;
			str++;
		}
		i += j;
	}
	return (i);
}*/

t_stack_master	*ft_args_to_stack_master(char **argv, int max_stack_size)
{
	t_stack_master	*stack_master;
	int i;
	int nb_i;

	stack_master = ft_initialize_stack_master();
	ft_create_stack_master(stack_master, max_stack_size);
	nb_i = 0;
	i = max_stack_size;
	while (i)
	{
		if (!ft_strncmp(argv[i], "-c", 2))
			stack_master->is_colored = 1;
		else if (!ft_strncmp(argv[i], "-v", 2))
			stack_master->is_verbose = 1;
		else if (!ft_strncmp(argv[i], "-i", 2))
			stack_master->is_instruction = 1;
		else if (!ft_strncmp(argv[i], "-h", 2))
			stack_master->is_hiding_default_output = 1;
		else if (!ft_strncmp(argv[i - 1], "-a", 2))
			stack_master->algo_version =
			*ft_atoi_utimate(argv[i--]);
		else {
			//nb_i += count_ints(argv[i]);
			ft_add(stack_master->a, argv[i]);
		}
		i--;
	}
	/*ft_create_stack_master(stack_master, nb_i);
	printf("DEBUG %d", nb_i);
	i = max_stack_size;
	while (i)
	{
		if (!ft_strncmp(argv[i], "-c", 2) && !ft_strncmp(argv[i], "-v", 2) && !ft_strncmp(argv[i], "-i", 2)
		&& !ft_strncmp(argv[i], "-h", 2) && !ft_strncmp(argv[i - 1], "-a", 2))
			continue ;
		else {
			add_int(stack_master, argv[i]);
			//ft_add(stack_master->a, argv[max_stack_size]);
		}
		i--;
	}*/
	return (stack_master);
}
