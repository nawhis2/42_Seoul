/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:27:28 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:49:09 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_list_gnl
{
	long long			*buf_info;
	char				*buf;
	struct s_list_gnl	*next;
}			t_list_gnl;

char		*ft_find_next_line(t_list_gnl *node, int fd);
char		*ft_make_str(t_list_gnl *node, char *str, \
size_t str_index, size_t str_max);
t_list_gnl	*ft_find_node(t_list_gnl *head, int fd);
char		*get_next_line(int fd);
char		*ft_realloc_gnl(char *str, size_t str_index, \
size_t	*str_max, int option);
void		*ft_calloc_gnl(size_t size, size_t count);

#endif