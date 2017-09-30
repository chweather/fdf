/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 15:02:13 by cweather          #+#    #+#             */
/*   Updated: 2017/09/29 15:53:55 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		filler(t_fdf *f, int x, int y)
{
	int			fd;
	char		*line;
	char		*tmp;
	char		**split;

	if ((fd = open(f->name, O_RDONLY)) < 0)
		error(ERR_NO_OPEN);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strtrim(line);
		split = ft_strsplit(tmp, 32);
		line ? ft_memdel((void *)&line) : (0);
		tmp ? ft_memdel((void *)&tmp) : (0);
		x = 0;
		while (x < f->map_x && split[x])
		{
			f->map[y][x].h1 = ft_atoi(split[x]);
			f->map[y][x].h1 > f->map_max ? f->map_max = f->map[y][x].h1 : 0;
			x++;
		}
		split ? ft_sstrdel(split) : (0);
		y++;
	}
	close(fd);
	ft_putstr("\e[1;32mOK\e[0m\n\t\tRendering... ");
}

static int		check_number(char *str)
{
	int			i;

	i = 0;
	if (str && str[i] == 45)
		i++;
	while (str && str[i])
	{
		if ((str[i] >= 48 && str[i] <= 58) || str[i] == 32 || str[i] == 45)
			i++;
		else
			return (1);
	}
	return (0);
}

static void		alloc(t_fdf *f, int i)
{
	((f->map_x * f->map_y) > 1000000) ? error(ERR_NOT_NUM) : (0);
	if (!(f->map = (t_pxl **)malloc(sizeof(t_pxl *) * f->map_y)))
		error(ERR_MALLOC);
	while (i < f->map_y)
		if (!(f->map[i++] = (t_pxl *)malloc(sizeof(t_pxl) * f->map_x)))
			error(ERR_MALLOC);
	filler(f, 0, 0);
}

void			parser(t_fdf *f)
{
	char		**split;
	char		*line;
	char		*tmp;
	int			fd;

	if ((fd = open(f->name, O_RDONLY)) < 0)
		error(ERR_NO_OPEN);
	if ((read(fd, NULL, 0)) < 0)
		error(ERR_NO_OPEN);
	while (get_next_line(fd, &line))
	{
		tmp = ft_strtrim(line);
		split = ft_strsplit(tmp, 32);
		line ? ft_memdel((void *)&line) : (0);
		check_number(tmp) ? error(ERR_NOT_NUM) : (0);
		tmp ? ft_memdel((void *)&tmp) : (0);
		(f->map_x == 0) ? f->map_x = ft_sstrlen(split) : (0);
		if (f->map_x != ft_sstrlen(split))
			error(ERR_NOT_EQU);
		split ? ft_sstrdel(split) : (0);
		f->map_y++;
	}
	close(fd);
	alloc(f, 0);
}
