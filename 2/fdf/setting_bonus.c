/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:42:32 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/03 12:33:13 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_validmap(char *map_argv, int fd)
{
	char	**title;
	int		i;

	i = 1;
	title = ft_split(map_argv, '.');
	while (title[i])
	{
		if (title[i + 1] == NULL && ft_strncmp(title[i], "fdf", 3) == 0)
		{
			if (fd < 0 || fd == 2)
			{
				ft_free_split(title);
				ft_printf("OPEN ERROR !\n");
				exit(-1);
			}
			ft_free_split(title);
			return ;
		}
		i++;
	}
	ft_free_split(title);
	ft_printf("INVALID MAP FORMAT!\n");
	exit(-1);
}

int	ft_check_xsize(int *map_size, int *max_x)
{
	if (map_size[0] == 0)
		return (-1);
	if (map_size[1] == 0)
	{
		*max_x = map_size[0];
	}
	else
		if (*max_x != map_size[0])
			return (-1);
	return (0);
}

int	ft_mapsize(t_mapinfo *maps, char *map_argv)
{
	int		fd;
	char	**elems;
	int		max_x;

	elems = NULL;
	fd = open(map_argv, O_RDONLY);
	ft_validmap(map_argv, fd);
	elems = ft_getline(elems, fd);
	while (elems)
	{
		maps->size_map[0] = 0;
		while (*elems && *elems[0] != '\n')
		{
			elems++;
			maps->size_map[0]++;
		}
		ft_free_split(elems - maps->size_map[0]);
		if (ft_check_xsize(maps->size_map, &max_x) == -1)
			ft_free_struct(maps, 0);
		maps->size_map[1]++;
		elems = ft_getline(elems, fd);
	}
	close(fd);
	return (0);
}

void	ft_free_split(char **elems)
{
	int	i;

	i = 0;
	while (elems[i])
	{
		free(elems[i]);
		i++;
	}
	free(elems);
	elems = NULL;
}

void	ft_free_struct(t_mapinfo *maps, int opt)
{
	int	i;
	int	j;

	i = 0;
	if (opt == 1)
	{
		while (i < maps->size_map[1])
		{
			j = 0;
			while (j < maps->size_map[0])
			{
				free(maps->point_3d[i][j]);
				free(maps->proj[i][j]);
				j++;
			}
			free(maps->point_3d[i]);
			free(maps->proj[i]);
			i++;
		}
	}
	free(maps->point_3d);
	free(maps->proj);
	free(maps->size_map);
	exit(-1);
}
