/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_xy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 19:13:28 by cweather          #+#    #+#             */
/*   Updated: 2017/09/26 22:08:00 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			check_line(char *str)
{
	int		i;

	i = 0;
	if (!*str)
		ft_error("Error: Line not read");
	while (str[i])
	{
		if (ft_isalpha(str[i]) == 1)
			ft_error("Error: Invalid characters detected");
		if ((str[i] == 45 && !(ft_isdigit(str[i + 1]))) || str[i] == 9)
			ft_error("Error: Invalid characters detected");
		i++;
	}
}

int				count_width(char **map_coord)
{
	int		i;

	i = 0;
	while (map_coord[i])
		i++;
	return (i);
}

int				get_width(t_drawline *arg, int fd, t_map *map, int y)
{
	int		width;
	char	**points;

	if (get_next_line(fd, &(arg->line)))
	{
		check_line(arg->line);
		if ((arg->points = ft_strsplit(arg->line, 32))
		== NULL || !*arg->points)
			ft_error("Error: Missing content");
		if (!(width = count_width(arg->points)))
			ft_error("Error: Invalid width");
		else
		{
			points = ft_strsplit(arg->line, 32);
			map->w = width;
		}
	}
	else
		ft_error("Error: Empty map");
	return (y);
}

void			get_height(t_drawline *arg, int fd, t_map *map, int y)
{
	char	**points;
	int		width;

	while (get_next_line(fd, &(arg->line)))
	{
		check_line(arg->line);
		if (!(width = count_width(arg->points)))
			ft_error("Error:Invalid width");
		else
			points = ft_strsplit(arg->line, 32);
		y++;
	}
	map->h = y;
	free(arg->points);
	free(arg->line);
	close(fd);
}

void			parse_xy(t_map *map, int fd, t_drawline *arg)
{
	int y;

	y = 0;
	get_width(arg, fd, map, y);
	get_height(arg, fd, map, y);
}
