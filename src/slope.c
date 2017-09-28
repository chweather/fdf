/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slope.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 18:42:54 by cweather          #+#    #+#             */
/*   Updated: 2017/09/27 18:58:59 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			slope_steep(t_env *fdf, t_drawline *values)
{
	float		x;

	values->delta = fabsf(fdf->run / fdf->rise);
	x = fdf->x1;
	if (fdf->y2 < fdf->y1)
	{
		values->tmp = fdf->y1;
		fdf->y1 = fdf->y2;
		fdf->y2 = values->tmp;
		x = fdf->x2;
	}
	values->tmp = fdf->y1;
	values->range = (fdf->y2 - values->tmp);
	while (fdf->y1 < fdf->y2)
	{
		values->color = color(fdf, values, fdf->y1 - values->tmp);
		mlx_pixel_put(fdf->mlx, fdf->win, x, fdf->y1, values->color);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			x += values->adjust;
			values->threshold += 1.0;
		}
		fdf->y1++;
	}
}

void			slope_gradual(t_env *fdf, t_drawline *values)
{
	float		y;

	values->delta = fabsf(fdf->m);
	y = fdf->y1;
	if (fdf->x2 < fdf->x1)
	{
		values->tmp = fdf->x1;
		fdf->x1 = fdf->x2;
		fdf->x2 = values->tmp;
		y = fdf->y2;
	}
	values->tmp = fdf->x1;
	values->range = (fdf->x2 - values->tmp);
	while (fdf->x1 < fdf->x2)
	{
		values->color = color(fdf, values, fdf->x1 - values->tmp);
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, y, values->color);
		values->offset += values->delta;
		if (values->offset >= values->threshold)
		{
			y += values->adjust;
			values->threshold += 1.0;
		}
		fdf->x1++;
	}
}

void			slope_flat(t_env *fdf)
{
	float		tmp;

	tmp = 0;
	if (fdf->y2 < fdf->y1)
	{
		tmp = fdf->y1;
		fdf->y1 = fdf->y2;
		fdf->y2 = tmp;
	}
	while (fdf->y1 <= fdf->y2)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->x1, fdf->y1, RED);
		fdf->y1++;
	}
}
