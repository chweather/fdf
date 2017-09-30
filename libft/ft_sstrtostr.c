/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:37:08 by cweather          #+#    #+#             */
/*   Updated: 2017/09/29 15:40:02 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_sstrtostr(char **s, char *sep)
{
	char		*tmp;
	char		*tmp2;
	int			i;

	tmp = NULL;
	tmp2 = NULL;
	tmp = ft_strjoin(s[0], sep);
	i = 1;
	while (s[i])
	{
		tmp2 = ft_strjoin(tmp, s[i]);
		ft_memdel((void *)&tmp);
		tmp = ft_strjoin(tmp2, sep);
		ft_memdel((void *)&tmp2);
		i++;
	}
	return (tmp);
}
