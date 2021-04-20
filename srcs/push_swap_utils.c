/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 16:34:47 by tglory            #+#    #+#             */
/*   Updated: 2021/04/20 07:36:31 by tglory           ###   ########lyon.fr   */
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
			if (stack->top > 100 || stack->top < 0)
			{
				printf("\tError while print, size not conformed\n");
				return ;
			}
			while (i <= stack->top)
				printf("%d ", stack->array[i++]);
				//printf("[%d] = %d, ", i, stack->array[i++]);
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

int*	ft_atoi_push_swap(const char *str)
{
	long	nb;
	int		neg;
	int		swap;
	int		*ret;
	int		i;
	int		tmp_i;

	ret = NULL;
	nb = 0;
	neg = 1;
	i = 0;
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
			|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		return (NULL);
	while ((*str >= '0' && *str <= '9') && *str != '\0')
	{
		tmp_i = *str - 48;
		if (i > 9 || (i > 8 && (nb > 214748364 || ((tmp_i > 8 && neg == -1) || (tmp_i > 7 && neg == 1)))))
			return (NULL);
		nb = nb * 10 + tmp_i;
		i++;
		str++;
	}
	swap = (int)nb * neg;
	ret = &swap;
	return (ret);
}
