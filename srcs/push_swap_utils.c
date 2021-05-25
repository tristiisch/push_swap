/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:34:47 by tglory            #+#    #+#             */
/*   Updated: 2021/05/24 16:37:55 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	printf("pile : ");
	if (stack != NULL)
	{
		if (ft_stack_is_empty(stack))
			printf("EMPTY");
		else
		{
			printf("size = %d > ", (stack->top + 1));
			if (stack->top > 500 || stack->top < 0)
			{
				printf("\tError while print, size not conformed or > 500\n");
				return ;
			}
			while (i <= stack->top)
				printf("%d ", stack->array[i++]);
		}
	}
	else
		printf("NULL");
	printf("\n");
}

void	ft_print_int_double_array(int **array, int size)
{
	int	i;

	i = 0;
	printf("int 2 array : ");
	if (array != NULL)
	{
		if (size == 0)
			printf("EMPTY");
		else
		{
			printf("size = %d > ", size);
			while (i < size)
			{
				printf("%d-%d ", array[i][0], array[i][1]);
				i++;
			}
		}
	}
	else
		printf("NULL");
	printf("\n");
}

void	ft_print_int_array(int *array, int size)
{
	int	i;

	i = 0;
	printf("int array : ");
	if (array != NULL)
	{
		if (size == 0)
			printf("EMPTY");
		else
		{
			printf("size = %d > ", size);
			while (i < size)
				printf("%d ", array[i++]);
		}
	}
	else
		printf("NULL");
	printf("\n");
}

void	ft_print_master_stack(t_stack_master *stack_master)
{
	printf("A ");
	ft_print_stack(stack_master->a);
	printf("B ");
	ft_print_stack(stack_master->b);
}
