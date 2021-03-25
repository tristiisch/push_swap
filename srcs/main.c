/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 15:12:19 by ksam             ###   ########lyon.fr   */
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

// int	main(void)
// {
// 	t_stack stack;

// 	stack.array_a[5] = {9, 5, 4, 3, 2};
// 	// stack.array_a = { };

// 	stack.length_a = sizeof(&stack.array_a) / sizeof(int);
// 	print_int_array(stack.array_a, stack.length_a);
// 	ft_swap(stack.array_a, stack.length_a);
// 	print_int_array(stack.array_a, stack.length_a);
// 	return (0);
// }
