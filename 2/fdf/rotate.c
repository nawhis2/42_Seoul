/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:40:21 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/03 12:33:06 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_mlx *ptrs, t_mapinfo *maps, double theta)
{
	int		x;
	int		y;
	double	tmp[3];

	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		while (x < maps->size_map[0])
		{
			tmp[1] = cos(theta) * (double)maps->point_3d[y][x][1] - \
			sin(theta) * (double)maps->point_3d[y][x][2];
			tmp[2] = sin(theta) * (double)maps->point_3d[y][x][1] + \
			cos(theta) * (double)maps->point_3d[y][x][2];
			maps->point_3d[y][x][1] = tmp[1];
			maps->point_3d[y][x][2] = tmp[2];
			ft_projection(maps, x, y);
			x++;
		}
		y++;
	}
	ptrs->img_data = mlx_get_data_addr(ptrs->img, \
	&ptrs->bpp, &ptrs->size_line, &ptrs->endian);
	ft_drawmap(ptrs, maps);
}

void	ft_rotate_y(t_mlx *ptrs, t_mapinfo *maps, double theta)
{
	int			x;
	int			y;
	double		tmp[3];

	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		while (x < maps->size_map[0])
		{
			tmp[0] = cos(theta) * (double)maps->point_3d[y][x][0] - \
			sin(theta) * (double)maps->point_3d[y][x][2];
			tmp[2] = sin(theta) * (double)maps->point_3d[y][x][0] + \
			cos(theta) * (double)maps->point_3d[y][x][2];
			maps->point_3d[y][x][0] = tmp[0];
			maps->point_3d[y][x][2] = tmp[2];
			ft_projection(maps, x, y);
			x++;
		}
		y++;
	}
	ptrs->img_data = mlx_get_data_addr(ptrs->img, \
	&ptrs->bpp, &ptrs->size_line, &ptrs->endian);
	ft_drawmap(ptrs, maps);
}

void	ft_rotate_z(t_mlx *ptrs, t_mapinfo *maps, double theta)
{
	int			x;
	int			y;
	double		tmp[3];

	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		while (x < maps->size_map[0])
		{
			tmp[0] = cos(theta) * (double)maps->point_3d[y][x][0] - \
			sin(theta) * (double)maps->point_3d[y][x][1];
			tmp[1] = sin(theta) * (double)maps->point_3d[y][x][0] + \
			cos(theta) * (double)maps->point_3d[y][x][1];
			maps->point_3d[y][x][0] = tmp[0];
			maps->point_3d[y][x][1] = tmp[1];
			ft_projection(maps, x, y);
			x++;
		}
		y++;
	}
	ptrs->img_data = mlx_get_data_addr(ptrs->img, \
	&ptrs->bpp, &ptrs->size_line, &ptrs->endian);
	ft_drawmap(ptrs, maps);
}

int	ft_isvalidelem(t_mapinfo *maps, char *e)
{
	int	i;
	int	comma_flag;

	i = 0;
	comma_flag = 0;
	if (!e)
		ft_free_struct(maps, 1);
	if (e[i] == '-')
		i++;
	while (e[i] && e[i] != '\n')
	{
		if ((e[i] >= '0' && e[i] <= '9') || e[i] == 'x' || e[i] == 'X' \
		|| (e[i] >= 'a' && e[i] <= 'f') || (e[i] >= 'A' && e[i] <= 'F'))
			i++;
		else if (i != 0 && comma_flag == 0 && e[i] == ',')
		{
			i++;
			comma_flag = 1;
		}
		else
			ft_free_struct(maps, 1);
	}
	return (0);
}
