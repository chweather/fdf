/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:56:30 by cweather          #+#    #+#             */
/*   Updated: 2017/07/06 20:10:38 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	size = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	size--;
	while (s1[i] && i < (int)n)
	{
		while (s1[i + j] == s2[j] && i + j < (int)n)
		{
			if (j == size)
				return ((char *)(s1 + i));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
