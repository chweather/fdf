/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:00:58 by cweather          #+#    #+#             */
/*   Updated: 2017/07/01 19:20:55 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	int			j;
	size_t		i;
	size_t		dst_len;
	size_t		src_len;

	i = ft_strlen(dest);
	j = 0;
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size < dst_len + 1)
		return (src_len + size);
	if (size > dst_len + 1)
	{
		while (i < size - 1)
			*(dest + i++) = *(src + j++);
		*(dest + i) = '\0';
	}
	return (dst_len + src_len);
}
