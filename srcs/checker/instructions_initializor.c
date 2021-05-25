/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_initializor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:38:37 by tglory            #+#    #+#             */
/*   Updated: 2021/05/25 12:28:52 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

char	**instructions_initializor(void)
{
	char	**array;

	array = malloc(sizeof(char *) * 11);
	array[0] = "sa";
	array[1] = "sb";
	array[2] = "ss";
	array[3] = "pa";
	array[4] = "pb";
	array[5] = "ra";
	array[6] = "rb";
	array[7] = "rr";
	array[8] = "rra";
	array[9] = "rrb";
	array[10] = "rrr";
	return (array);
}
