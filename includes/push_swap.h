/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/30 05:32:19 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

#define INT_MAX	2147483647
#define INT_MIN	(-INT_MAX-1)


typedef struct s_stack
{
    int		top;
    int		capacity;
    int*	array;
}			t_stack;

/*
typedef struct s_stack
{
	int		i;
	struct  s_stack	*next;
}			t_stack;*/

/*
typedef struct s_stack
{
	int		*array;
	size_t	length;
}			t_stack;
*/
typedef struct s_stack_master
{
	t_stack	*a;
	t_stack	*b;
}			t_stack_master;

void	ft_swap(t_stack *stack);
void	ft_push(t_stack_master *stack, int bool);
void	ft_rotate(t_stack *stack);
void	ft_reverse_rotate(t_stack *stack);

void	ft_print_stack(t_stack *stack);
void	ft_print_master_stack(t_stack_master *stack_master);
void	ft_init_stack_master(t_stack_master *stack_master);
void	ft_init_stack(t_stack *stack);

void	sort(t_stack_master *stack_master, char *operator);
void	jump_to_index(t_stack *stack, int index);
void	test_sort(t_stack_master *stack_master);

int			ft_stack_peek(t_stack* stack);
int			ft_stack_pop(t_stack* stack);
void		ft_stack_push(t_stack* stack, int item);
int			ft_stack_is_empty(t_stack* stack);
int 		ft_stack_is_full(t_stack* stack);
t_stack*	ft_stack_create(unsigned capacity);
t_stack* 	ft_stack_duplicate_push(t_stack* old_stack, int new_item);

#endif