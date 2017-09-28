/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:36:45 by cweather          #+#    #+#             */
/*   Updated: 2017/07/01 15:55:32 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *i;

	if (len == 0)
		return (b);
	i = (unsigned char *)b;
	while (len--)
	{
		*i = (unsigned char)c;
		if (len)
			i++;
	}
	return (b);
}
