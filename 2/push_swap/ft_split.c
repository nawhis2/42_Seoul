/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:42:13 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 13:46:18 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_n_words(char const *s, char c);
static size_t	ft_n_char(char const *s, char c);
static void		*ft_calloc2(size_t count, size_t size);

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	num;

	num = 0;
	if (s == 0 || *s == '\0')
		ft_errors();
	words = (char **)ft_calloc2((ft_n_words(s, c) + 1), sizeof(char *));
	if (!words)
		ft_errors();
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s == 0)
			break ;
		words[num] = (char *)ft_calloc2((ft_n_char(s, c) + 1), sizeof(char));
		if (!words[num])
			ft_errors();
		ft_memcpy(words[num++], s, ft_n_char(s, c));
		s += ft_n_char(s, c);
	}
	return (words);
}

static size_t	ft_n_words(char const *s, char c)
{
	size_t	index;
	size_t	len;
	size_t	num_words;

	len = 0;
	num_words = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c)
			len++;
		else if (s[index] == c && len)
		{
			num_words++;
			len = 0;
		}
		index++;
	}
	if (len)
		num_words++;
	return (num_words);
}

static size_t	ft_n_char(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
			len++;
		else
			return (len);
		s++;
	}
	return (len);
}

static void	*ft_calloc2(size_t count, size_t size)
{
	void	*mem;

	if (size != 0 && (count * size) / size != count)
		return (0);
	mem = malloc2(count * size);
	ft_bzero(mem, count * size);
	return (mem);
}
