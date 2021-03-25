/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:08:51 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 14:34:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *list, size_t length)
{
	int	swap;
	int	index;

	if (length < 2)
		return ;
	index = length - 1;
	swap = list[index];
	list[index] = list[index - 1];
	list[index - 1] = swap;
}

void	ft_push(t_stack stack, int bool)
{
	int	swap;
	int	index;

	if (length < 2)
		return ;
	index = length - 1;
	swap = list[index];
	list[index] = list[index - 1];
	list[index - 1] = swap;
}
