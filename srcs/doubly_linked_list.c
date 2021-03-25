/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 18:01:09 by ksam              #+#    #+#             */
/*   Updated: 2021/03/25 18:01:39 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_master	*manager_initializor(void)
{
	t_master *manager;

	manager = malloc(sizeof(t_master));
	if (manager == NULL)
		exit(1);
	manager->first = NULL;
	manager->last = NULL;
	manager->current = NULL;
	manager->count = 0;
	return (manager);
}

void		data_backpusher(t_master *manager, char *val)
{
	t_data	*new;

	new = ft_calloc(1, sizeof(t_data));
	if (new == NULL)
		exit(1);
	new->prev = manager->last;
	new->val = val;
	if (!manager->first)
		manager->first = new;
	if (manager->last)
		manager->last->next = new;
	manager->last = new;
	manager->count++;
}

void		data_frontpusher(t_master *manager, char *val)
{
	t_data *new;

	new = ft_calloc(1, sizeof(t_data));
	if (new == NULL)
		exit(1);
	new->next = manager->first;
	new->val = val;
	manager->first = new;
	manager->count++;
	if (new->next)
		new->next->prev = new;
	if (!manager->last)
		manager->last = new;
}

void		data_eraser(t_master *manager, t_data *new, int i)
{
	if (new == manager->first)
	{
		if (new->next)
			new->next->prev = NULL;
		manager->first = new->next;
	}
	else
		new->prev->next = new->next;
	if (new == manager->last)
	{
		if (new->prev)
			new->prev->next = NULL;
		manager->last = new->prev;
	}
	else
		new->next->prev = new->prev;
	if (i == 1)
		free(new->val);
	free(new);
	manager->count--;
}