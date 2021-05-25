/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:57:53 by tglory            #+#    #+#             */
/*   Updated: 2021/05/22 22:23:05 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error_master(t_stack_master *stack_master, char *msg)
{
	dprintf(2, "\033[0;31mError\n%s.\033[0m\n", msg);
	ft_stack_master_free(stack_master);
	exit(EXIT_FAILURE);
}

void	ft_error(char *msg)
{
	dprintf(2, "\033[0;31mError\n%s.\033[0m\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_error_memomy(void)
{
	ft_error("Unable to allocate memory");
}

void	ft_warn(char *msg)
{
	printf("\x1B[33mWarn\n%s.\033[0m\n", msg);
}
