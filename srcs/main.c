/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 12:58:02 by tglory            #+#    #+#             */
/*   Updated: 2021/03/25 16:09:12 by ksam             ###   ########lyon.fr   */
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
	int	a[]	= {9, 5, 4, 3};
	int	b[]	= {};
	t_stack	stack;

	stack.array_a = a;
	stack.array_b = b;
	stack.length_a = sizeof(a) / sizeof(int);
	stack.length_b = sizeof(b) / sizeof(int);
	printf("test 1\n");
	print_int_array(stack.array_a, stack.length_a);
	print_int_array(stack.array_b, stack.length_b);
	//ft_swap(a, length);
	//ft_push(&stack, 1);
	//ft_push(&stack, 0);
	printf("test 2\n");
	print_int_array(stack.array_a, stack.length_a);
	print_int_array(stack.array_b, stack.length_b);
	return (0);
}
