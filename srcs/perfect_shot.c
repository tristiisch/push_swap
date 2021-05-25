/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perfect_shot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:32:36 by tglory            #+#    #+#             */
/*   Updated: 2021/05/24 16:37:52 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_perfect_shot	*init_perfect_shot(void)
{
	t_perfect_shot	*p_shot;

	p_shot = ft_calloc(1, sizeof(t_perfect_shot));
	if (p_shot == NULL)
		ft_error_memomy();
	p_shot->i_a = 0;
	p_shot->i_b = 0;
	p_shot->t_a = -1;
	p_shot->t_b = -1;
	p_shot->t_total = -1;
	return (p_shot);
}

void	ft_perfect_shot_b2(t_stack_master *stack_master, int min_b, int max_b,
	t_perfect_shot *ps)
{
	ps->v1 = ft_get_cercle(ps->i_b, stack_master->b);
	ps->v2 = ft_get_cercle(ps->i_b + 1, stack_master->b);
	ps->i_a = 0;
	while (ps->i_a <= stack_master->a->top)
	{
		ps->value = stack_master->a->array[ps->i_a];
		if ((ps->v1 < ps->value && ps->value < ps->v2)
			|| ((ps->v1 < ps->value || ps->v2 > ps->value)
				&& ps->v2 == min_b && ps->v1 == max_b))
		{
			ps->t_a = index_to_times(ps->i_a, stack_master->a->top);
			ps->t_b = index_to_times(ps->i_b, stack_master->b->top);
			if (ps->t_a + ps->t_b == 0 || ps->t_total == -1
				|| ps->t_a + ps->t_b < ps->t_total)
			{
				ps->t_total = ps->t_a + ps->t_b;
				ps->saved_a = ps->i_a;
				ps->saved_b = ps->i_b;
			}
		}
		ps->i_a++;
	}
	ps->i_b++;
}

int	ft_perfect_shot_b(t_stack_master *stack_master, int min_b, int max_b)
{
	t_perfect_shot	*ps;

	ps = init_perfect_shot();
	while (ps->i_b <= stack_master->b->top)
		ft_perfect_shot_b2(stack_master, min_b, max_b, ps);
	if (ps->t_total < 0)
		ft_error("Cannot find perfect shot B");
	jump_to_index_both(stack_master, ps->saved_a, ps->saved_b);
	free(ps);
	ft_sort_and_print(stack_master, "pb");
	return (1);
}

void	ft_perfect_shot_a2(t_stack_master *stack_master, int min_a, int max_a,
	t_perfect_shot *ps)
{
	ps->v1 = ft_get_cercle(ps->i_a, stack_master->a);
	ps->v2 = ft_get_cercle(ps->i_a + 1, stack_master->a);
	ps->i_b = 0;
	while (ps->i_b <= stack_master->b->top)
	{
		ps->value = stack_master->b->array[ps->i_b];
		if ((ps->v1 > ps->value && ps->value > ps->v2)
			|| ((ps->v1 > ps->value || ps->v2 < ps->value)
				&& ps->v2 == max_a && ps->v1 == min_a))
		{
			ps->t_a = index_to_times(ps->i_a, stack_master->a->top);
			ps->t_b = index_to_times(ps->i_b, stack_master->b->top);
			if (ps->t_a + ps->t_b == 0 || ps->t_total == -1
				|| ps->t_a + ps->t_b < ps->t_total)
			{
				ps->t_total = ps->t_a + ps->t_b;
				ps->saved_a = ps->i_a;
				ps->saved_b = ps->i_b;
			}
		}
		ps->i_b++;
	}
	ps->i_a++;
}

int	ft_perfect_shot_a(t_stack_master *stack_master, int min_a, int max_a)
{
	t_perfect_shot	*ps;

	ps = init_perfect_shot();
	while (ps->i_a <= stack_master->a->top)
		ft_perfect_shot_a2(stack_master, min_a, max_a, ps);
	if (ps->t_total < 0)
		ft_error("Cannot find perfect shot A");
	jump_to_index_both(stack_master, ps->saved_a, ps->saved_b);
	free(ps);
	ft_sort_and_print(stack_master, "pa");
	return (1);
}
