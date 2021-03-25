/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:54:15 by tglory            #+#    #+#             */
/*   Updated: 2020/10/26 17:54:15 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (*(s + i) == (char)c)
		return ((char *)s + i);
	while (*(s + i) != '\0')
	{
		if (*(s + i) == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}
