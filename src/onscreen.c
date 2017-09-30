/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onscreen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/30 01:25:34 by cweather          #+#    #+#             */
/*   Updated: 2017/09/30 02:03:32 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		data_var(t_fdf *f, int off_x, int off_y)
{
	char		*tmp;
	char		*vtmp;

	vtmp = ft_itoa(f->height);
	tmp = ft_strjoin("Multiplier:", vtmp);
	mlx_string_put(f->mlx.mlx, f->mlx.win, 5, f->win_y - 25, 0x3399FF, tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
	vtmp = ft_itoa(f->speed);
	tmp = ft_strjoin("Speed:", vtmp);
	off_x = f->win_x - (ft_strlen(tmp) * 10) - 5;
	off_y = f->win_y - 25;
	mlx_string_put(f->mlx.mlx, f->mlx.win, off_x, off_y, 0x3399FF, tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
}

static void		data_xyz(t_fdf *f, int off_x)
{
	char		*tmp;
	char		*vtmp;
	char		*rt;

	tmp = NULL;
	vtmp = ft_itoa(f->pos_x);
	tmp = ft_strjoin("X:", vtmp);
	rt = ft_strjoin(tmp, " Y:");
	tmp ? ft_memdel((void *)&tmp) : (0);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
	vtmp = ft_itoa(f->pos_y);
	tmp = ft_strjoin(rt, vtmp);
	rt ? ft_memdel((void *)&rt) : (0);
	rt = ft_strjoin(tmp, " Z:");
	tmp ? ft_memdel((void *)&tmp) : (0);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
	vtmp = ft_itoa(f->pos_z);
	tmp = ft_strjoin(rt, vtmp);
	off_x = (f->win_x - (ft_strlen(tmp) * 10)) / 2;
	mlx_string_put(f->mlx.mlx, f->mlx.win, off_x, f->win_y - 25, 0xCC0033, tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
	rt ? ft_memdel((void *)&rt) : (0);
}

static void		data_msize(t_fdf *f)
{
	char		*tmp;
	char		*vtmp;
	char		*rt;
	int			offset;

	vtmp = ft_itoa(f->map_x);
	rt = ft_strjoin("X:", vtmp);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
	tmp = ft_strjoin(rt, " Y:");
	rt ? ft_memdel((void *)&rt) : (0);
	vtmp = ft_itoa(f->map_y);
	rt = ft_strjoin(tmp, vtmp);
	offset = (f->win_x - (ft_strlen(rt) * 10)) / 2;
	mlx_string_put(f->mlx.mlx, f->mlx.win, offset, 20, 0x00ceFF, rt);
	rt ? ft_memdel((void *)&rt) : (0);
	tmp ? ft_memdel((void *)&tmp) : (0);
	vtmp ? ft_memdel((void *)&vtmp) : (0);
}

void			screeninfo(t_fdf *f)
{
	char		*tmp;
	int			offset;

	tmp = NULL;
	tmp = ft_strjoin("MAP:", f->name);
	offset = (f->win_x - (ft_strlen(tmp) * 10)) / 2;
	mlx_string_put(f->mlx.mlx, f->mlx.win, offset, 0, 0x00FF00, tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	data_msize(f);
	data_xyz(f, 0);
	data_var(f, 0, 0);
}
