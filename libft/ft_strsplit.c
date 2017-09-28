/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 20:31:37 by cweather          #+#    #+#             */
/*   Updated: 2017/07/04 20:36:28 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_cnt_parts(const char *s, char c)
{
	int		a;
	int		b;

	b = 0;
	a = 0;
	while (*s != '\0')
	{
		if (b == 1 && *s == c)
			b = 0;
		if (b == 0 && *s != c)
		{
			b = 1;
			a++;
		}
		s++;
	}
	return (a);
}

static int	ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		nb_word;
	int		i;

	i = 0;
	if (!s || !c)
		return (NULL);
	nb_word = ft_cnt_parts((const char *)s, c);
	t = (char **)malloc(sizeof(*t) * (ft_cnt_parts((const char *)s, c) + 1));
	if (t == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		t[i] = ft_strsub((const char *)s, 0, ft_wlen((const char *)s, c));
		if (t[i] == NULL)
			return (NULL);
		s = s + ft_wlen(s, c);
		i++;
	}
	t[i] = NULL;
	return (t);
}
