/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:13:57 by cweather          #+#    #+#             */
/*   Updated: 2017/09/29 14:21:01 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "libft.h"
# include "keys.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define DEBUG			0
# define ERR_ARG		"Invalid arguments. Usage: ./test_maps.fdf"
# define ERR_NO_OPEN	"File error: Failed to open the file"
# define ERR_MALLOC		"Malloc error"
# define ERR_NOT_NUM	"Map error: invalid character in map"
# define ERR_NOT_EQU	"Map error: Lines are not equal in length"

typedef struct			s_line
{
	float				a;
	float				b;
	float				c;
}						t_line;

typedef struct			s_pxl
{
	int					x;
	int					y;
	int					h;
	int					x1;
	int					y1;
	int					h1;
}						t_pxl;

typedef struct			s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
}						t_mlx;

typedef struct			s_fdf
{
	char				*name;
	t_mlx				mlx;
	int					win_x;
	int					win_y;
	t_pxl				**map;
	int					map_x;
	int					map_y;
	int					map_max;
	int					height;
	int					zoom;
	int					speed;
	int					clr;
	float				pos_x;
	float				pos_y;
	float				pos_z;
}						t_fdf;

void					parser(t_fdf *f);
void					recalc(t_fdf *f, int x, int y);
void					img_gen(t_fdf *f);
int						mlx_img(t_fdf *f, t_pxl a);
void					screeninfo(t_fdf *f);
void					error(char *reason);

#endif
