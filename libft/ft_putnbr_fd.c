/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 19:03:21 by cweather          #+#    #+#             */
/*   Updated: 2017/07/06 19:56:06 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long count;

	count = n;
	if (count < 0)
	{
		ft_putchar_fd('-', fd);
		count *= -1;
	}
	if (count >= 10)
	{
		ft_putnbr_fd(count / 10, fd);
		ft_putchar_fd((count % 10) + 48, fd);
	}
	else
		ft_putchar_fd(count + 48, fd);
}
