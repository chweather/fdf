/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 15:02:06 by cweather          #+#    #+#             */
/*   Updated: 2017/06/09 15:02:08 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int a;
	int pos;
	int len;

	a = 0;
	pos = 0;
	len = 0;
	while (to_find[len])
		len++;
	if (len == 0)
		return (str);
	while (str[a])
	{
		while (to_find[pos] == str[a + pos])
		{
			if (pos == len - 1)
				return (str + a);
			pos++;
		}
		pos = 0;
		a++;
	}
	return (0);
}
