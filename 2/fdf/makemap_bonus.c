/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makemap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:43:20 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/03 12:10:04 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_drawmap(t_mlx *ptrs, t_mapinfo *maps)
{
	ft_makeline_x(ptrs, maps);
	ft_makeline_y(ptrs, maps);
	mlx_put_image_to_window(ptrs->mlx, ptrs->win, ptrs->img, 0, 0);
}

char	**ft_getline(char **elems, int fd)
{
	char	*s;

	s = get_next_line(fd);
	elems = ft_split(s, ' ');
	free(s);
	return (elems);
}

long	ft_parsecolor(char *s)
{
	long		res;

	res = 0;
	s = s + 2;
	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
			res = res * 16 + (*s - '0');
		else if (*s >= 'A' && *s <= 'F')
			res = res * 16 + (*s - 'A' + 10);
		else if (*s >= 'a' && *s <= 'f')
			res = res * 16 + (*s - 'a' + 10);
		s++;
	}
	return (res);
}

void	ft_maptoarr(t_mapinfo *maps, char *map_elem, int x, int y)
{
	char	**alt_color;

	if (x == 0 && map_elem[0] == '\n')
		ft_free_struct(maps, 1);
	else if (map_elem[0] == '\n')
		return ;
	alt_color = ft_split(map_elem, ',');
	if (alt_color[1])
		maps->proj[y][x][2] = ft_parsecolor(alt_color[1]);
	else
		maps->proj[y][x][2] = 0xFFFFFF;
	maps->point_3d[y][x][0] = x;
	maps->point_3d[y][x][1] = y;
	maps->point_3d[y][x][2] = ft_atoi(alt_color[0]);
	ft_free_split(alt_color);
	ft_projection(maps, x, y);
}

void	ft_readmap(t_mlx *ptrs, t_mapinfo *maps)
{
	char			**map_line;
	int				x;
	int				y;
	int				fd;

	map_line = NULL;
	fd = open(maps->arg_data, O_RDONLY);
	if (ft_make2dmaparr(maps) == -1)
		ft_free_struct(maps, 1);
	y = 0;
	while (y < maps->size_map[1])
	{
		x = 0;
		map_line = ft_getline(map_line, fd);
		while (x < maps->size_map[0])
		{
			ft_isvalidelem(maps, map_line[x]);
			ft_maptoarr(maps, map_line[x], x, y);
			x++;
		}
		ft_free_split(map_line);
		y++;
	}
	close(fd);
	ft_drawmap(ptrs, maps);
}
