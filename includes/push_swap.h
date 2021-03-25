/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 15:04:21 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>

void	ft_swap(int *array, size_t length);

typedef struct s_stack
{
	size_t	length_a;
	size_t	length_b;
	int		*array_a;
	int		*array_b;
}			t_stack;

#endif