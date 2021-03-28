/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/28 23:55:21 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_stack
{
	int		*array;
	size_t	length;
}			t_stack;

typedef struct s_stack_master
{
	t_stack	a;
	t_stack	b;
}			t_stack_master;

void	ft_swap(t_stack *stack);
void	ft_push(t_stack_master *stack, int bool);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);
void	ft_print_stack(t_stack *stack);
void	ft_print_master_stack(t_stack_master *stack_master);

void	sort(t_stack_master *stack_master, char *operator);
void	jump_to_index(t_stack *stack, int index);
void	test_sort(t_stack_master *stack_master);

#endif