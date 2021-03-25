/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:55:04 by tglory            #+#    #+#             */
/*   Updated: 2021/02/11 03:11:32 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int length;

	length = ft_strlen(s) + 1;
	while (0 < length--)
		if (s[length] == (char)c)
			return ((char *)&s[length]);
	return (NULL);
}
