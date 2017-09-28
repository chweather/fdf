/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:09:07 by cweather          #+#    #+#             */
/*   Updated: 2017/06/20 16:27:10 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	if ((s = malloc(sizeof(char) * size)) != NULL)
	{
		while (i < size)
			s[i++] = 0;
	}
	return (s);
}
