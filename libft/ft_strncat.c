/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:01:24 by cweather          #+#    #+#             */
/*   Updated: 2017/06/09 15:01:26 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, int nb)
{
	int len;
	int a;

	len = 0;
	a = 0;
	while (dest[len])
		len++;
	while (a < nb && src[a])
	{
		dest[len] = src[a];
		len++;
		a++;
	}
	dest[len] = '\0';
	return (dest);
}
