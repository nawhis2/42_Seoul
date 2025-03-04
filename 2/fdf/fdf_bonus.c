/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 15:54:27 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/03 12:09:24 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	p_x(t_mlx *ptrs, t_mapinfo *maps, int tmp, int start)
{
	int	pixel;

	pixel = (maps->mid_y + tmp) * ptrs->size_line + \
			(maps->mid_x + start) * (ptrs->bpp / 8);
	return (pixel);
}

int	p_y(t_mlx *ptrs, t_mapinfo *maps, int tmp, int start)
{
	int	pixel;

	pixel = (maps->mid_y + start) * ptrs->size_line + \
			(maps->mid_x + tmp) * (ptrs->bpp / 8);
	return (pixel);
}

void	ft_makeline_x(t_mlx *ptrs, t_mapinfo *maps)
{
	int	x;
	int	y;

	y = 0;
	while (maps->proj[y])
	{
		x = 1;
		while (maps->proj[y][x])
		{
			if (labs(maps->proj[y][x][0] - maps->proj[y][x - 1][0]) \
			> labs(maps->proj[y][x][1] - maps->proj[y][x - 1][1]))
				ft_xline_x(ptrs, maps, x, y);
			else
				ft_xline_y(ptrs, maps, x, y);
			x++;
		}
		y++;
	}
}

void	ft_makeline_y(t_mlx *ptrs, t_mapinfo *maps)
{
	int	x;
	int	y;

	y = 1;
	while (maps->proj[y])
	{
		x = 0;
		while (maps->proj[y][x])
		{
			if (labs(maps->proj[y][x][0] - maps->proj[y - 1][x][0]) \
			> labs(maps->proj[y][x][1] - maps->proj[y - 1][x][1]))
				ft_yline_x(ptrs, maps, x, y);
			else
				ft_yline_y(ptrs, maps, x, y);
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_mlx		ptrs;
	t_mapinfo	maps;
	t_param		param;

	ft_starting(&maps);
	if (argc != 2)
		exit(1);
	maps.size_map = (int *)ft_calloc(sizeof(int), 2);
	if (!maps.size_map || ft_mapsize(&maps, argv[1]) == -1)
		ft_free_struct(&maps, 0);
	ptrs.mlx = mlx_init();
	ptrs.win = mlx_new_window(ptrs.mlx, maps.img_x, maps.img_y, "FdF");
	ptrs.img = mlx_new_image(ptrs.mlx, maps.img_x, maps.img_y);
	maps.arg_data = argv[1];
	ptrs.img_data = mlx_get_data_addr(ptrs.img, &ptrs.bpp, \
					&ptrs.size_line, &ptrs.endian);
	if (ft_make3dmaparr(&maps) == -1)
		ft_free_struct(&maps, 1);
	ft_readmap(&ptrs, &maps);
	param.ptrs = &ptrs;
	param.maps = &maps;
	mlx_key_hook(ptrs.win, key_hook, &param);
	mlx_hook(ptrs.win, 17, 0, ft_exit, &maps);
	mlx_loop(ptrs.mlx);
	return (0);
}
