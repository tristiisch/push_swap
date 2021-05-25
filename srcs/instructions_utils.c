/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 03:00:06 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:37:41 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	colored_instructions2(t_stack_master *stack_master)
{
	int	pt;

	pt = -1;
	if (stack_master->a->capacity == 3)
	{
		if (stack_master->instructions <= 3)
			pt = 5;
		else
			pt = 0;
	}
	else if (stack_master->a->capacity == 500)
	{
		if (stack_master->instructions <= 5500)
			pt = 5;
		else if (stack_master->instructions <= 7000)
			pt = 4;
		else if (stack_master->instructions <= 8500)
			pt = 3;
		else if (stack_master->instructions <= 10000)
			pt = 2;
		else if (stack_master->instructions <= 11500)
			pt = 1;
	}
	return (pt);
}

int	colored_instructions(t_stack_master *stack_master)
{
	int	pt;

	pt = 0;
	if (stack_master->a->capacity == 5)
	{
		if (stack_master->instructions <= 12)
			pt = 5;
	}
	else if (stack_master->a->capacity == 100)
	{
		if (stack_master->instructions <= 700)
			pt = 5;
		else if (stack_master->instructions <= 900)
			pt = 4;
		else if (stack_master->instructions <= 1100)
			pt = 3;
		else if (stack_master->instructions <= 1300)
			pt = 2;
		else if (stack_master->instructions <= 1500)
			pt = 1;
	}
	else
		return (colored_instructions2(stack_master));
	return (pt);
}

void	ft_print_instructions(t_stack_master *stack_master)
{
	int	pt;

	pt = colored_instructions(stack_master);
	if (pt == 5)
		printf("\e[42mPERFECT ");
	else if (pt == 4)
		printf("\e[92mTrès Bien ");
	else if (pt == 3)
		printf("\e[32mBien ");
	else if (pt == 2)
		printf("\e[96mPeux mieux faire ");
	else if (pt == 1)
		printf("\e[93mBof ");
	else if (pt == 0)
	{
		printf("\e[101mKO ");
	}
	printf("%d instructions pour %d chiffres\033[0m\n",
		stack_master->instructions, stack_master->a->capacity);
}
