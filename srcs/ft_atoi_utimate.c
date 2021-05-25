/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_utimate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 08:07:40 by ksam              #+#    #+#             */
/*   Updated: 2021/05/24 16:35:52 by ksam             ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*ft_atoi_utimate2(const char *str, long nb, int neg, int *ret)
{
	int		swap;
	int		i;

	i = 0;
	if (!(*str >= '0' && *str <= '9'))
		return (NULL);
	while (*str >= '0' && *str <= '9')
	{
		nb = nb * 10 + (*str - 48);
		if (i++ > 10 || (neg == -1 && nb > 2147483648)
			|| (neg == 1 && nb > 2147483647))
			return (NULL);
		str++;
	}
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
		|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str != 0)
		return (NULL);
	swap = ((int)nb * neg);
	ret = &swap;
	return (ret);
}

/** Atoi without allowing letter, and check INT range. It return a pointer
 * @return int* or NULL if @param str is not in INT range
 */
int	*ft_atoi_utimate(const char *str)
{
	long	nb;
	int		neg;
	int		*ret;

	nb = 0;
	neg = 1;
	ret = NULL;
	while ((*str == '\t') || (*str == '\v') || (*str == '\n')
		|| (*str == '\r') || (*str == '\f') || (*str == ' '))
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (ft_atoi_utimate2(str, nb, neg, ret));
}
