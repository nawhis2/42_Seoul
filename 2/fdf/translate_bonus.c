/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 19:41:12 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/03 12:11:11 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	ft_transdown(t_param *param)
{
	param->ptrs->img_data = mlx_get_data_addr(param->ptrs->img, \
	&param->ptrs->bpp, &param->ptrs->size_line, &param->ptrs->endian);
	param->maps->mid_y += 100;
	ft_drawmap(param->ptrs, param->maps);
}

void	ft_transup(t_param *param)
{
	param->ptrs->img_data = mlx_get_data_addr(param->ptrs->img, \
	&param->ptrs->bpp, &param->ptrs->size_line, &param->ptrs->endian);
	param->maps->mid_y -= 100;
	ft_drawmap(param->ptrs, param->maps);
}

void	ft_transleft(t_param *param)
{
	param->ptrs->img_data = mlx_get_data_addr(param->ptrs->img, \
	&param->ptrs->bpp, &param->ptrs->size_line, &param->ptrs->endian);
	param->maps->mid_x -= 100;
	ft_drawmap(param->ptrs, param->maps);
}

void	ft_transright(t_param *param)
{
	param->ptrs->img_data = mlx_get_data_addr(param->ptrs->img, \
	&param->ptrs->bpp, &param->ptrs->size_line, &param->ptrs->endian);
	param->maps->mid_x += 100;
	ft_drawmap(param->ptrs, param->maps);
}
