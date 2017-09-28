/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 14:53:17 by cweather          #+#    #+#             */
/*   Updated: 2017/06/20 16:48:49 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int a;
	int num;
	int negative;

	num = 0;
	negative = 0;
	a = 0;
	while ((str[a] == '\n') || (str[a] == '\t') || (str[a] == '\v') ||
		(str[a] == ' ') || (str[a] == '\f') || (str[a] == '\r'))
		a++;
	if (str[a] == '-')
		negative = 1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] && (str[a] >= '0') && (str[a] <= '9'))
	{
		num *= 10;
		num += (int)str[a] - '0';
		a++;
	}
	if (negative == 1)
		return (-num);
	else
		return (num);
}
