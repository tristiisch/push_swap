/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/04/12 15:51:45 by tglory           ###   ########lyon.fr   */
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
	int		top;
	int		capacity;
	int		*array;
}	t_stack;

typedef struct s_perfect_stack
{
	int		**perfect_array_a;
	int		size_a;
	int		**perfect_array_b;
	int		size_b;
}	t_perfect_stack;

typedef struct s_stack_master
{
	t_stack	*a;
	t_stack	*b;
	int		instruction;
}			t_stack_master;

void			ft_swap(t_stack *stack);
void			ft_push(t_stack_master *stack, int bool);
void			ft_rotate(t_stack *stack);
void			ft_reverse_rotate(t_stack *stack);

void			ft_print_stack(t_stack *stack);
void			ft_print_master_stack(t_stack_master *stack_master);

void			sort(t_stack_master *stack_master, char *operator);
void			jump_to_index(t_stack_master *stack_master,
					int index, int a_or_b);
void			test_sort(t_stack_master *stack_master);
int				get_index_of_biggest(t_stack *stack, int under);
int				get_index_of_smallest(t_stack *stack, int upper);

int				ft_stack_peek(t_stack *stack);
int				ft_stack_pop(t_stack *stack);
void			ft_stack_push(t_stack *stack, int item);
int				ft_stack_is_empty(t_stack *stack);
int				ft_stack_is_full(t_stack *stack);
t_stack			*ft_stack_create(unsigned int capacity);
t_stack			*ft_stack_add(t_stack *old_stack, int new_item);
int				ft_stack_has_place(t_stack *stack, int i);
void			ft_stack_free_stack(t_stack *stack);
t_stack*		ft_add(t_stack *stack, char* s);
void			ft_print_int_array(int *array, int size);
void			ft_print_int_double_array(int **array, int size);

int				ft_is_correct_order(t_stack *stack);
int				ft_is_updside_down(t_stack *stack);
int				ft_is_correct(t_stack_master *stack_master);

void			ft_free_perfect_stack(t_perfect_stack perfect_stack);
t_perfect_stack	ft_get_perfect_stack(t_stack_master *stack_master);
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

/*
**_________________________________CHECKER_________________________________
*/

/*
** 					CHECKER FUNCTIONS
*/
int					*transform_argument_to_array(int argc, char**argv);
t_stack_master		*fill_astack_with_arg(int *nb, int argc);


#endif