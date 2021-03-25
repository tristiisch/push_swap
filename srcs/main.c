/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 13:39:55 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_int_array(int **list)
{
	size_t	length;

	length = sizeof(list) / sizeof(int);
	printf("list (%zu elements) : ", *length);
	while (length > 0)
		printf("%d ", *list[length--]);
	printf("\n");
}

int	main(void)
{
	int	a[] = {9, 5, 4, 3, 2};
	int	b[] = { };

	print_int_array(a);
	ft_swap(a);
	print_int_array(a);
	return (0);
}
