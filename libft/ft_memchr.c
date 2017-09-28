/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:22:30 by cweather          #+#    #+#             */
/*   Updated: 2017/07/01 15:57:22 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	i = 0;
	ch = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n--)
	{
		if (ptr[i] == ch)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
