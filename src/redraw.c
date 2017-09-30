/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 00:56:15 by cweather          #+#    #+#             */
/*   Updated: 2017/09/30 01:25:00 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		straight(t_fdf *f, t_pxl a, t_pxl b, int sense)
{
	if (a.y == b.y)
	{
		sense = (a.x > b.x) ? -1 : 1;
		while (a.x != b.x)
		{
			mlx_img(f, a);
			a.x += sense;
		}
		mlx_img(f, a);
	}
	else
	{
		sense = (a.y > b.y) ? -1 : 1;
		while (a.y != b.y)
		{
			mlx_img(f, a);
			a.y += sense;
		}
		mlx_img(f, a);
	}
}

static void		diagonal_x(t_fdf *f, t_pxl steps, t_pxl point, float m)
{
	float		start;
	int			i;
	int			n;
	t_pxl		a;

	i = steps.x;
	n = steps.y;
	start = point.y;
	a.x = i;
	a.y = start;
	mlx_img(f, a);
	while (i <= n)
	{
		a.x = i;
		a.y = start;
		mlx_img(f, a);
		start += m;
		i++;
	}
}

static void		diagonal_y(t_fdf *f, t_pxl steps, t_pxl point, float m)
{
	float		start;
	int			i;
	int			n;
	t_pxl		a;

	i = steps.x;
	n = steps.y;
	start = point.x;
	a.x = start;
	a.y = i;
	mlx_img(f, a);
	while (i <= n)
	{
		a.x = start;
		a.y = i;
		mlx_img(f, a);
		start += m;
		i++;
	}
}

static void		join_pixel(t_fdf *f, t_pxl pix_a, t_pxl pix_b)
{
	float		m;
	t_pxl		shift;

	if (pix_a.x == pix_b.x || pix_a.y == pix_b.y)
		straight(f, pix_a, pix_b, 0);
	else if (abs(pix_a.x - pix_b.x) > abs(pix_a.y - pix_b.y))
	{
		m = ((float)(pix_b.y - pix_a.y)) / (pix_b.x - pix_a.x);
		shift.x = (int)fmin(pix_a.x, pix_b.x);
		shift.y = (int)fmax(pix_a.x, pix_b.x);
		diagonal_x(f, shift, (pix_a.x < pix_b.x) ? pix_a : pix_b, m);
	}
	else
	{
		m = ((float)(pix_b.x - pix_a.x)) / (pix_b.y - pix_a.y);
		shift.x = (int)fmin(pix_a.y, pix_b.y);
		shift.y = (int)fmax(pix_a.y, pix_b.y);
		diagonal_y(f, shift, (pix_a.y < pix_b.y) ? pix_a : pix_b, m);
	}
}

void			img_gen(t_fdf *f)
{
	int			y;
	int			x;

	recalc(f, 0, 0);
	f->mlx.img = mlx_new_image(f->mlx.mlx, f->win_x, f->win_y);
	y = 0;
	while (y < f->map_y)
	{
		x = 0;
		while (x < f->map_x)
		{
			if (y != f->map_y - 1)
				join_pixel(f, f->map[y][x], f->map[y + 1][x]);
			if (x != f->map_x - 1)
				join_pixel(f, f->map[y][x], f->map[y][x + 1]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(f->mlx.mlx, f->mlx.win, f->mlx.img, 0, 0);
	mlx_destroy_image(f->mlx.mlx, f->mlx.img);
	screeninfo(f);
}
