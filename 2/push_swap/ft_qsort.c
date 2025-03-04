/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:40:10 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 14:34:31 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_get_pivot(t_stack *a)
{
	t_list	*tmp;
	int		*pivot;
	t_list	**array;
	int		size;
	int		i;

	pivot = (int *)malloc2(sizeof(int) * 2);
	array = ft_val_array(a);
	size = a->size;
	ft_quicksort(array, 0, size - 1);
	i = 0;
	tmp = a->head;
	while (i++ < size - 1)
	{
		if (array[i]->val == array[i - 1]->val)
			ft_errors();
		array[i - 1]->val = i;
	}
	array[size - 1]->val = size;
	pivot[0] = array[size / 3 - 1]->val;
	pivot[1] = array[size / 3 * 2 - 1]->val;
	free(array);
	return (pivot);
}

t_list	**ft_val_array(t_stack *a)
{
	int		size;
	int		i;
	t_list	*node;
	t_list	**array;

	i = 0;
	size = a->size;
	node = a->head;
	array = (t_list **)malloc2(sizeof(t_list *) * size);
	while (i < size)
	{
		array[i++] = node;
		node = node->next;
	}
	return (array);
}

void	ft_quicksort(t_list **array, int left, int right)
{
	int	pi;

	if (left >= right)
		return ;
	pi = ft_qsrt_partition(array, left, right);
	ft_quicksort(array, left, pi - 1);
	ft_quicksort(array, pi + 1, right);
}

int	ft_qsrt_partition(t_list **array, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[left]->val;
	i = left;
	j = right;
	while (i < j)
	{
		while (pivot < array[j]->val)
			j--;
		while (i < j && pivot >= array[i]->val)
			i++;
		ft_swap(array, i, j);
	}
	ft_swap(array, left, i);
	return (i);
}

void	ft_swap(t_list **array, int i, int j)
{
	t_list	*tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}
