/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:41:49 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/03 12:11:21 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	ft_exit(t_mapinfo *maps)
{
	ft_free_struct(maps, 1);
	return (0);
}

void	ft_zoomin(t_param *param)
{
	int	x;
	int	y;

	if (param->maps->zoom_level < 20)
		param->maps->zoom_level++;
	y = 0;
	while (y < param->maps->size_map[1])
	{
		x = 0;
		while (x < param->maps->size_map[0])
		{
			ft_projection(param->maps, x, y);
			x++;
		}
		y++;
	}
	ft_drawmap(param->ptrs, param->maps);
}

void	ft_zoomout(t_param *param)
{
	int	x;
	int	y;

	if (param->maps->zoom_level > 1)
		param->maps->zoom_level--;
	y = 0;
	while (y < param->maps->size_map[1])
	{
		x = 0;
		while (x < param->maps->size_map[0])
		{
			ft_projection(param->maps, x, y);
			x++;
		}
		y++;
	}
	ft_drawmap(param->ptrs, param->maps);
}
