/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:54:51 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 05:08:31 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*dst;

	if (!(s == NULL || f == NULL))
	{
		i = ft_strlen((char *)s);
		dst = malloc(sizeof(*s) * ((i + 1)));
		if (dst == NULL)
			return (dst);
		i = 0;
		while (s[i] != '\0')
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (0);
}
