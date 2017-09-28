/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:59:53 by cweather          #+#    #+#             */
/*   Updated: 2017/07/01 18:12:51 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, const char *src)
{
	int len;
	int a;

	len = 0;
	a = 0;
	while (dest[len])
		len++;
	while (src[a])
	{
		dest[len] = src[a];
		a++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
