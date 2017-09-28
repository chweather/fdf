/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 19:00:10 by cweather          #+#    #+#             */
/*   Updated: 2017/09/27 20:22:59 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				set_color(t_drawline *values, float distance)
{
	if (distance <= (values->range * 0.10))
		return (0x00FF4500);
	else if (distance <= (values->range * 0.20))
		return (0x00FF5719);
	else if (distance <= (values->range * 0.30))
		return (0x00FF6A32);
	else if (distance <= (values->range * 0.40))
		return (0x00FF7C4C);
	else if (distance <= (values->range * 0.50))
		return (0x00FF8F66);
	else if (distance <= (values->range * 0.60))
		return (0x00FFA27F);
	else if (distance <= (values->range * 0.70))
		return (0x00FFB499);
	else if (distance <= (values->range * 0.80))
		return (0x00FFC7B2);
	else if (distance <= (values->range * 0.90))
		return (0x00FFD9CC);
	else if (distance <= (values->range))
		return (0x00FFD9CC);
	return (0x006600FF);
}

int				color(t_env *fdf, t_drawline *values, float dist)
{
	if ((fdf->next_z || fdf->z) > fdf->hmin)
	{
		if (fdf->z == fdf->next_z)
			return (0x00FF0000);
		else if (fdf->z != fdf->next_z)
			return (set_color(values, dist));
	}
	return (0x00FF0000);
}
