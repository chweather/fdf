/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:44:43 by cweather          #+#    #+#             */
/*   Updated: 2017/09/27 14:09:12 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coord		**plot_cart(t_env *fdf, t_map *m)
{
	int			i;
	int			j;
	t_coord		**cart;

	fdf->mid_x = m->w / 2;
	fdf->mid_y = m->h / 2;
	cart = (t_coord **)malloc(sizeof(t_coord *) * (m->h + 1));
	i = 0;
	while (i < m->h)
	{
		cart[i] = (t_coord *)malloc(sizeof(t_coord) * (m->w + 1));
		j = 0;
		while (j < m->w)
		{
			cart[i][j].x = ((j - fdf->mid_x) * fdf->gap);
			cart[i][j].y = ((i - fdf->mid_y) * fdf->gap);
			cart[i][j].z = m->map_ptr[i][j] * 5;
			cart[i][j].raw_z = m->map_ptr[i][j];
			j++;
		}
		i++;
	}
	return (cart);
}

void		fill_env(t_env **fdf, t_map *m)
{
	(*fdf)->x1 = 0;
	(*fdf)->x2 = 0;
	(*fdf)->y1 = 0;
	(*fdf)->y2 = 0;
	(*fdf)->hmin = 0;
	(*fdf)->gap = m->w >= m->h ? 700 / (m->w) : 700 / (m->h);
	(*fdf)->big = m->w >= m->h ? m->w : m->h;
	(*fdf)->w = m->w;
	(*fdf)->h = m->h;
	(*fdf)->rise = 0;
	(*fdf)->run = 0;
	(*fdf)->m = 0;
	(*fdf)->win_w = 350 + ((*fdf)->gap) * ((*fdf)->big);
	(*fdf)->win_h = ((*fdf)->win_w) - 100;
	(*fdf)->cart = plot_cart(*fdf, m);
	(*fdf)->mlx = mlx_init();
	(*fdf)->win =
	mlx_new_window((*fdf)->mlx, (*fdf)->win_w, (*fdf)->win_h, "FdF");
}

t_env		*make_env(t_map *map)
{
	t_env		*fdf;

	if (!(fdf = (t_env *)malloc(sizeof(t_env))))
		ft_error("Error: Failed to allocate memory");
	fill_env(&fdf, map);
	return (fdf);
}
