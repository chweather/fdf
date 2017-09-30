/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recalc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:59:35 by cweather          #+#    #+#             */
/*   Updated: 2017/09/29 16:42:19 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		shifting(t_fdf *f, t_pxl *px)
{
	float		angle;
	float		x[2];

	angle = (3.14159265 * f->pos_x) / 180;
	x[0] = px->h * cos(angle) + px->y1 * sin(angle);
	x[1] = px->y1 * cos(angle) - px->h * sin(angle);
	px->h = round(x[0]);
	px->y1 = round(x[1]);
	angle = (3.14159265 * f->pos_y) / 180;
	x[0] = px->x1 * cos(angle) + px->h * sin(angle);
	x[1] = px->h * cos(angle) - px->x1 * sin(angle);
	px->x1 = round(x[0]);
	px->h = round(x[1]);
	angle = (3.14159265 * f->pos_z) / 180;
	x[0] = px->x1 * cos(angle) + px->y1 * sin(angle);
	x[1] = px->y1 * cos(angle) - px->x1 * sin(angle);
	px->x1 = round(x[0]);
	px->y1 = round(x[1]);
}

void			recalc(t_fdf *f, int x, int y)
{
	t_line		tmp;

	y = 0;
	while (y < f->map_y)
	{
		x = 0;
		while (x < f->map_x)
		{
			f->map[y][x].x1 = f->zoom * (x - f->map_x / 2);
			f->map[y][x].y1 = f->zoom * (y - f->map_y / 2);
			f->map[y][x].h = f->map[y][x].h1 * f->height;
			shifting(f, &f->map[y][x]);
			tmp.a = f->map[y][x].x1;
			tmp.b = f->map[y][x].y1;
			tmp.c = f->map[y][x].h - 1000;
			f->map[y][x].x = (tmp.a / tmp.c) * (250 - 1000);
			f->map[y][x].x += f->win_x / 2;
			f->map[y][x].y = (tmp.b / tmp.c) * (250 - 1000);
			f->map[y][x].y += f->win_y / 2;
			x++;
		}
		y++;
	}
}

int				mlx_img(t_fdf *f, t_pxl a)
{
	char		*px;
	int			bpp;
	int			endian;
	int			len;
	int			i;

	if (a.x >= f->win_x || a.y >= f->win_y || a.x < 0 || a.y < 0)
		return (1);
	i = 0;
	px = mlx_get_data_addr(f->mlx.img, &bpp, &len, &endian);
	if (endian == 0)
		while (i != bpp / 8)
		{
			px[a.y * len + a.x * (bpp / 8) + i++] = (0x000000FF & f->clr);
			px[a.y * len + a.x * (bpp / 8) + i++] = (0x0000FF00 & f->clr) >> 8;
			px[a.y * len + a.x * (bpp / 8) + i++] = (0x00FF0000 & f->clr) >> 16;
			px[a.y * len + a.x * (bpp / 8) + i++] = (0xFF000000 & f->clr) >> 24;
		}
	return (0);
}
