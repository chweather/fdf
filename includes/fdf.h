/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:13:57 by cweather          #+#    #+#             */
/*   Updated: 2017/09/27 21:15:05 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "mlx.h"
# include "libft.h"
# include <math.h>
# include <stdio.h>
# define RED 0x00FF0000
# define WHITE 0x00FFFFFF
# define BLUE 0x00242cf8

typedef struct			s_coord
{
	float				x;
	float				y;
	float				z;
	float				raw_z;
}						t_coord;

typedef struct			s_map
{
	int					**map_ptr;
	int					win_x;
	int					win_y;
	int					hmax;
	int					hmin;
	int					h;
	int					w;
}						t_map;

typedef struct			t_drawline
{
	char				*str;
	char				**points;
	char				*line;
	float				delta;
	float				offset;
	float				threshold;
	float				adjust;
	float				color;
	float				range;
	float				tmp;
}						t_drawline;

typedef struct			s_env
{
	t_coord				**cart;
	float				x1;
	float				x2;
	float				y1;
	float				y2;
	int					gap;
	int					big;
	float				rise;
	float				run;
	float				m;
	float				win_h;
	float				win_w;
	int					mid_x;
	int					mid_y;
	int					i;
	int					j;
	int					h;
	int					w;
	float				z;
	float				next_z;
	int					hmin;
	void				*mlx;
	void				*win;
}						t_env;

void					parse_xy(t_map *map, int fd, t_drawline *arg);
int						get_width(t_drawline *arg, int fd, t_map *map, int y);
void					get_height(t_drawline *arg, int fd, t_map *map, int y);
int						count_width(char **map_coord);
void					check_line(char *str);
void					parse_z(t_map *m, int fd);
int						*split_atoi(char **s, int w);
t_env					*make_env(t_map *map);
t_coord					**plot_cart(t_env *fdf, t_map *m);
void					fill_env(t_env **fdf, t_map *m);
void					plot_lines(t_env *fdf);
void					values_down(t_env **fdf, int i, int j);
void					draw_down(t_env *fdf, t_drawline **values);
void					values_right(t_env **fdf, int i, int j);
void					draw_right(t_env *fdf, t_drawline **values);
void					slope_steep(t_env *fdf, t_drawline *values);
void					slope_gradual(t_env *fdf, t_drawline *values);
void					slope_flat(t_env *fdf);
void					translate(t_env *fdf);
void					rotate_x(t_env *fdf);
void					rotate_z(t_env *fdf);
int						color(t_env *fdf, t_drawline *values, float dist);
int						set_color(t_drawline *values, float distance);

#endif
