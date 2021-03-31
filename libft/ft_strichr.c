/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 19:57:23 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 05:07:39 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strichr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if ((*(s + i) == (char)c) && i == 0)
		return (-42);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char)c)
			return (i);
		i++;
	}
	return (0);
}
