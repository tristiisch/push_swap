/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/26 14:03:45 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"


typedef struct		s_data
{
	char			*val;
	int				free;
	struct s_data	*prev;
	struct s_data	*next;
}					t_data;

typedef struct		s_master
{
	unsigned int	count;
	t_data			*first;
	t_data			*last;
	t_data			*current;
}					t_master;

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

/*
**___________________________DOUBLY LINKED LIST___________________________
*/

/*
** 					DOUBLY LINKED LIST FUNCTIONS
*/
t_master			*manager_initializor();
void				data_backpusher(t_master *manager, char *val);
void				data_frontpusher(t_master *manager, char *val);
void				data_eraser(t_master *manager, t_data *new, int i);


#endif