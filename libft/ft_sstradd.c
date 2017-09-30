/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstradd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:20:30 by cweather          #+#    #+#             */
/*   Updated: 2017/09/29 15:23:16 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_sstradd(char **s, char *add)
{
	char		**rt;
	int			i;

	i = 0;
	rt = ft_sstrnew(ft_sstrlen(s) + 1);
	while (s[i])
	{
		rt[i] = ft_strdup(s[i]);
		i++;
	}
	rt[i] = ft_strdup(add);
	ft_sstrdel(s);
	s = rt;
	return (rt);
}
