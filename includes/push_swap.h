/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 16:08:20 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	size_t	length_a;
	size_t	length_b;
	int		*array_a;
	int		*array_b;
}			t_stack;

void	ft_swap(int *array, size_t length);
void	ft_push(t_stack *stack, int bool);
void	print_int_array(int *list, size_t length);

#endif