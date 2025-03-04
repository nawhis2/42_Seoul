/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:37:55 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 19:55:22 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *)b)[index] = (unsigned char)c;
		index++;
	}
	return (b);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	index;

	index = 0;
	if (!dst && !src)
		return (dst);
	while (index < n)
	{
		((unsigned char *)dst)[index] = ((unsigned char *)src)[index];
		index++;
	}
	return (dst);
}

int	ft_atoi(char *str)
{
	long long	sign;
	long long	value;
	long long	index;

	sign = 1;
	value = 0;
	index = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (str[index] == '-')
	{
		sign *= -1;
		str++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		if (index > 10)
			ft_errors();
		value = 10 * value + (str[index] - '0');
		index++;
	}
	if (!(sign * value >= -2147483648 && sign * value <= 2147483647) || \
	(index == 0 && str[index] == '\0') || str[index] != '\0')
		ft_errors();
	return ((int)sign * value);
}

void	*malloc2(int size)
{
	void	*tmp;

	tmp = malloc(size);
	if (!tmp)
		ft_errors();
	return (tmp);
}
