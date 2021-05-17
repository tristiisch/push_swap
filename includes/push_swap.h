/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 13:05:23 by tglory            #+#    #+#             */
/*   Updated: 2021/05/17 08:47:01 by tglory           ###   ########lyon.fr   */
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
	int		instructions;
	int		is_instruction;
	int		is_verbose;
	int		is_colored;
	int		algo_version;
	int		is_hiding_default_output;
}			t_stack_master;


void			ft_print_int_array(int *array, int size);
void			ft_print_int_double_array(int **array, int size);
void			ft_print_stack(t_stack *stack);
void			ft_print_master_stack(t_stack_master *stack_master);

int				ft_sort(t_stack_master *stack_master, char *operator);
void			ft_stack_master_free(t_stack_master *stack_master);

int				ft_stack_peek(t_stack *stack);
int				ft_stack_pop(t_stack *stack);
void			ft_stack_push(t_stack *stack, int item);
int				ft_stack_is_empty(t_stack *stack);
int				ft_stack_is_full(t_stack *stack);
t_stack			*ft_stack_create(unsigned int capacity);
t_stack			*ft_stack_add(t_stack *old_stack, int new_item);
int				ft_stack_has_place(t_stack *stack, int i);
void			ft_stack_free_stack(t_stack *stack);
t_stack			*ft_add(t_stack *stack, char* s);

void			ft_free_perfect_stack(t_perfect_stack perfect_stack);
t_perfect_stack	ft_get_perfect_stack(t_stack_master *stack_master);
t_stack_master	*ft_duplicate_stack_master(t_stack_master *stack_master);

t_stack_master	*ft_args_to_stack_master(char **argv, int max_stack_size);
t_stack_master	*ft_initialize_stack_master();
void			ft_create_stack_master(t_stack_master *stack_master, int max_stack_size);

int*			ft_atoi_utimate(const char *str);

void    		ft_warn(char *msg);
void    		ft_error(char *msg);
void			ft_error_master(t_stack_master *stack_master, char *msg);
void    		ft_error_memomy();

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
void				check_instructions(t_master *manager, char **instructions);
t_stack_master		*fill_astack_with_arg(int *nb, int argc);

/*
** 					FREE FUNCTIONS
*/
void				free_all(int *number_to_order, t_stack_master *stack_master);
void				free_manager(t_master *manager);

/*
** 					INSTRUCTIONS INITIALIZOR
*/
char				**instructions_initializor(void);

/*
** 					TRANSFORM ARGUMENT TO ARRAY
*/
int					*transform_argument_to_array(int argc, char**argv);
int					*reverse_array(int *array, int argc);

/*
**_________________________________PUSH SWAP_________________________________
*/
/*
** 					BASIC SORT
*/
int					ft_swap(t_stack *stack);
int					ft_push(t_stack_master *stack, int bool);
int					ft_rotate(t_stack *stack);
int					ft_reverse_rotate(t_stack *stack);

/*
** 					CHECKER PARTICULARITY
*/
int					ft_is_correct_order(t_stack *stack);
int					ft_is_upside_down(t_stack *stack);
int					ft_is_correct(t_stack_master *stack_master);
int					ft_can_be_revert(t_stack *stack, int **perfect_array);
int					can_be_revert_process(t_stack *stack, int **perfect_array, \
										int one, int two);
int					is_bad_index_only_b(t_stack_master *stack_master);
int					is_bad_index_only(t_stack_master *stack_master);

/*
** 					UTILS
*/
int*				get_index_of_biggest(t_stack *stack, int *under);
int*				get_index_of_smallest(t_stack *stack, int *upper);
void				jump_to_index(t_stack_master *stack_master, int index, int a_or_b);
void				jump_to_index_both(t_stack_master *stack_master, int index_a, int index_b);
int					index_to_times(int index, int top);
int 				ft_get_cercle(int index, t_stack *stack);
int 				ft_get_perfect_index_b(int value, int **perfect_stack_array, int perfect_stack_size, t_stack *stackDest);
int					*ft_random_integers(int nb, int max_nb);
int					ft_contain_int(int *nbs, int i, int size);

/*
** 					EXECUTE
*/

int					ft_sort_and_print(t_stack_master *stack_master, char *operator);
void				ft_auto_sort(t_stack_master *stack_master);
void 				ft_auto_sortV4(t_stack_master *stack_master);
void				ft_auto_sortV5(t_stack_master *stack_master);

/*
** 					TEST
*/
void				ft_test_all(int is_big_numbers);
void				ft_test_all_algos(t_stack_master *stack_master, int argc, char **argv);
void				ft_test_all_algos_random(int nb, int is_big_numbers);
void				ft_test_all_algos_numbers(int *nbs, int size);

void				ft_print_instructions(t_stack_master *stack_master);

#endif