/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 18:52:47 by cweather          #+#    #+#             */
/*   Updated: 2017/07/06 20:24:28 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long count;

	count = n;
	if (count == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (count < 0)
	{
		ft_putchar('-');
		count *= -1;
	}
	if (count >= 10)
	{
		ft_putnbr(count / 10);
		ft_putchar(count % 10 + '0');
	}
	else
		ft_putchar(count + 48);
}
