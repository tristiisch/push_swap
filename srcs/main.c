/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 14:15:06 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_int_array(int *list, size_t length)
{
	int		index = 0;

	printf("list (%zu elements) : ", length);
	while (length > index)
		printf("%d ", list[index++]);
	printf("\n");
}

int	main(void)
{
	int	a[] = {9, 5, 4, 3, 2};
	int	b[] = { };
	size_t length = sizeof(a) / sizeof(int);
	print_int_array(a, length);
	ft_swap(a, length);
	print_int_array(a, length);
	return (0);
}
