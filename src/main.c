/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cweather <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 19:14:57 by cweather          #+#    #+#             */
/*   Updated: 2017/09/27 21:14:38 by cweather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			main(int argc, char **argv)
{
	t_env			*fdf;
	t_map			*map;
	t_drawline		arg;
	int				fd;

	if (argc != 2)
		ft_error("Error: Invlaid arguments");
	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		ft_error("Error: Failed to allocate memory");
	if ((arg.str = ft_strstr(argv[1], ".fdf")) == 0)
		ft_error("Error: Invalid file extension");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Error: Failed to open the file");
	parse_xy(map, fd, &arg);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error("Error: Failed to open the file");
	parse_z(map, fd);
	fdf = make_env(map);
	plot_lines(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
