/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 18:11:25 by ksam             ###   ########lyon.fr   */
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
	size_t	length_a;
	size_t	length_b;
	int		*array_a;
	int		*array_b;
}			t_stack;

void	ft_swap(int *array, size_t length);
void	ft_push(t_stack *stack, int bool);
void	print_int_array(int *list, size_t length);

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