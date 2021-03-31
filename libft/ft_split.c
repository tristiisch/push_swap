/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:54:11 by tglory            #+#    #+#             */
/*   Updated: 2021/03/31 05:06:55 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (*str[i] != '\0')
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	*ft_cpyword(char *dst, char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[(*i)] == c)
		(*i)++;
	while (s[(*i)] != c && s[(*i)] != '\0')
	{
		dst[len] = s[*i];
		len++;
		(*i)++;
	}
	dst[len] = '\0';
	return (dst);
}

static int	ft_lenword(char const *s, char c, int *i)
{
	int	len;

	len = 0;
	while (s[(*i)] == c)
		(*i)++;
	while (s[(*i)] != c && s[(*i)] != '\0')
	{
		len++;
		(*i)++;
	}
	return (len);
}

static int	ft_countword(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i] != c && (i > 0) && s[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	int		l;
	int		count;
	int		i;
	char	**str;

	len = 0;
	l = 0;
	i = 0;
	if (s == 0)
		return ((char **)ft_strdup(""));
	count = ft_countword(s, c);
	str = (char **)malloc(sizeof(char *) * count);
	if (str == 0)
		return (0);
	while (i < count)
	{
		str[i] = (char *)malloc(sizeof(char) * ft_lenword(s, c, &len) + 1);
		if (str[i] == 0)
			return (ft_free(str));
		str[i] = ft_cpyword(str[i], s, c, &l);
		i++;
	}
	str[i] = 0;
	return (str);
}
