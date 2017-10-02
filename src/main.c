/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:14:57 by cweather          #+#    #+#             */
/*   Updated: 2017/10/02 14:11:47 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		instructions(void)
{
	ft_putendl("\e[1;32mOK\e[0m\n");
	ft_putendl("\t  FDF is controlled with the");
	ft_putendl("\t      numpad mapped as:\n");
	ft_putendl("\t -Q = RED  W = GREEN  E = BLUE-\n");
	ft_putendl("\t\e[90m┌──────┬──────┬──────┬──────┐\e[0m");
	ft_putendl("\t\e[90m| clear|    = |    / |    * |\e[0m");
	ft_putendl("\t\e[90m|      |      |      |      |\e[0m");
	ft_putendl("\t\e[90m├──────┼──────┼──────┼──────┤\e[0m");
	ft_putendl("\t\e[90m|    7 |    8 |    9 |    - |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;36mM-\e[90m  |  \e[1;32mY+\e[90m  |  ");
	ft_putstr("\e[1;36mM+\e[90m  |  \e[93mS-\e[90m  |\n\e[0m");
	ft_putendl("\t\e[90m├──────┼──────┼──────┼──────┤\e[0m");
	ft_putendl("\t\e[90m|    4 |    5 |    6 |    + |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;31mX-\e[90m  | \e[0mRST\e[90m  |  ");
	ft_putstr("\e[1;31mX+\e[90m  |  \e[93mS+\e[90m  |\n\e[0m");
	ft_putendl("\t\e[90m├──────┼──────┼──────┼──────┤\e[0m");
	ft_putendl("\t\e[90m|    1 |    2 |    3 |      |\e[0m");
	ft_putstr("\t\e[90m|  \e[1;94mR-\e[90m  |  \e[1;32mY-\e[90m  |  ");
	ft_putstr("\e[1;94mR+\e[90m  |      |\n\e[0m");
	ft_putendl("\t\e[90m├──────┴──────┼──────┤      |\e[0m");
	ft_putendl("\t\e[90m|             |      |      |\e[0m");
	ft_putendl("\t\e[90m|      0      |    . | enter|\e[0m");
	ft_putendl("\t\e[90m└─────────────┴──────┴──────┘\e[0m");
	ft_putendl("\n\t  \e[1;104;97m Press [ESC] to quit FDF \e[0m\n\n");
}

void			error(char *reason)
{
	ft_putendl_fd("\e[1;31mKO\n", 2);
	ft_putendl_fd(reason, 2);
	ft_putstr_fd("\e[0m", 2);
	exit(EXIT_FAILURE);
}

static void		defaults(t_fdf *f)
{
	f->win_x = ((f->map_x > f->map_y) ? f->map_x : f->map_y) * 10;
	(f->win_x < 800) ? f->win_x = 800 : (0);
	(f->win_x > 1920) ? f->win_x = 1920 : (0);
	f->win_y = (f->win_x * 9) / 16;
	f->zoom = f->win_y / ((f->map_x > f->map_y) ? f->map_x : f->map_y);
	if (!f->zoom)
		f->zoom = 2;
	f->height = 1;
	f->pos_x = 30;
	f->pos_y = 0;
	f->pos_z = 0;
	f->clr = 0xFFFFFF;
	f->speed = 3;
}

static int		keyhook(int key, t_fdf *f)
{
	f->pos_x >= 360 ? f->pos_x -= 360 : (0);
	f->pos_y >= 360 ? f->pos_y -= 360 : (0);
	f->pos_z >= 360 ? f->pos_z -= 360 : (0);
	f->pos_x <= -360 ? f->pos_x += 360 : (0);
	f->pos_y <= -360 ? f->pos_y += 360 : (0);
	f->pos_z <= -360 ? f->pos_z += 360 : (0);
	(key == K_ESC) ? exit(0) : (0);
	(key == RESET) ? defaults(f) : (0);
	(key == HPOS) ? f->height++ : (0);
	(key == HNEG && f->height) ? f->height-- : (0);
	(key == SPOS && f->speed < 10) ? f->speed++ : (0);
	(key == SNEG && f->speed) ? f->speed-- : (0);
	(key == XPOS) ? f->pos_x += f->speed : (0);
	(key == XNEG) ? f->pos_x -= f->speed : (0);
	(key == YPOS) ? f->pos_y += f->speed : (0);
	(key == YNEG) ? f->pos_y -= f->speed : (0);
	(key == RNEG) ? f->pos_z += f->speed : (0);
	(key == RPOS) ? f->pos_z -= f->speed : (0);
	(key == K_Q) ? f->clr = 0xFF0000 : (0);
	(key == K_W) ? f->clr = 0x00FF00 : (0);
	(key == K_E) ? f->clr = 0x0000FF : (0);
	((f->height * f->map_max) > (f->win_y / 2)) ? f->height-- : (0);
	(!f->height) ? f->height++ : (0);
	img_gen(f);
	return (0);
}

int				main(int argc, char **argv)
{
	t_fdf		fdf;

	if (argc != 2)
		error(ERR_ARG);
	fdf.name = ft_strdup(argv[1]);
	fdf.map_x = 0;
	fdf.map_y = 0;
	fdf.map_max = 0;
	ft_putstr("\t\t Parsing... ");
	parser(&fdf);
	defaults(&fdf);
	fdf.mlx.mlx = mlx_init();
	fdf.mlx.win = mlx_new_window(fdf.mlx.mlx, fdf.win_x, fdf.win_y, "fdf");
	img_gen(&fdf);
	instructions();
	mlx_hook(fdf.mlx.win, 2, (1L << 0), &keyhook, &fdf);
	mlx_loop(fdf.mlx.mlx);
	return (0);
}
