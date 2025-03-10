/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:25:47 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:07:07 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list_gnl	head;
	t_list_gnl			*nodes[2];
	char				*ret;

	if (fd < 0 || fd == 2)
		return (0);
	ret = ft_find_next_line(&head, fd);
	if (ret == 0 && head.next)
	{
		nodes[0] = &head;
		nodes[1] = nodes[0]->next;
		while (nodes[1]->buf_info[0] != fd)
		{
			nodes[0] = nodes[1];
			nodes[1] = nodes[1]->next;
			if (!nodes[1])
				return (0);
		}
		nodes[0]->next = nodes[1]->next;
		free(nodes[1]->buf_info);
		free(nodes[1]->buf);
		free(nodes[1]);
	}
	return (ret);
}
