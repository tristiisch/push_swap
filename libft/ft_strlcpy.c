/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:54:39 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 05:07:57 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	while ((src[i] != '\0') && size && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	if (size)
		dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}
