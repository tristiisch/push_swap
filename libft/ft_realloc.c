/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:54:07 by tglory            #+#    #+#             */
/*   Updated: 2020/10/26 17:54:07 by tglory           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	char	*newptr;

	if (!(newptr = ft_calloc(new_size, sizeof(unsigned char))))
		return (NULL);
	if (ptr)
	{
		if (old_size > new_size)
			old_size = new_size;
		ft_memcpy(newptr, ptr, old_size);
		free(ptr);
		ptr = NULL;
	}
	return (newptr);
}
