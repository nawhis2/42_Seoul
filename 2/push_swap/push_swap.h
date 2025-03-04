/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sihkang <sihkang@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:15:01 by sihkang           #+#    #+#             */
/*   Updated: 2024/01/15 20:47:47 by sihkang          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_count
{
	int	b_count;
	int	b_rev;
	int	a_count;
	int	a_rev;
	int	both;
}				t_count;

typedef struct s_list
{
	int				val;
	struct s_count	*cnt;
	struct s_list	*next;
	struct s_list	*prev;
}				t_list;

typedef struct s_stack
{
	int		size;
	t_list	*head;
	t_list	*tail;
}				t_stack;

t_stack	*ft_stack_init(void);
void	ft_argsplit(int argc, char **argv, t_stack *a);
void	ft_push(t_stack *st, t_list *new);
void	ft_pop(t_stack *st);
void	ft_s(t_stack *st, char c);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_p(t_stack *st1, t_stack *st2, char c);
void	ft_r(t_stack *st, char c);
void	ft_rr(t_stack *st, char c);
void	ft_r_r(t_stack *a, t_stack *b);
void	ft_rr_r(t_stack *a, t_stack *b);
int		ft_isascending(t_stack *st, int val);
void	ft_getargv(t_stack *st, char *argv);
int		ft_atoi(char *str);
void	ft_partition(t_stack *a, t_stack *b, int *pivot);
int		*ft_get_pivot(t_stack *a);
t_list	**ft_val_array(t_stack *a);
void	ft_quicksort(t_list **array, int left, int right);
int		ft_qsrt_partition(t_list **array, int left, int right);
void	ft_swap(t_list **array, int i, int j);
void	ft_small_nums(t_stack *a);
void	ft_startingtest(t_stack *a);
void	ft_finalsort(t_stack *a);
void	ft_greedysrt(t_stack *a, t_stack *b);
t_list	*ft_findmin(t_stack *b);
void	ft_nums(t_stack *a, t_stack *b);
void	ft_num_srt_a(t_stack *a, t_list *b_node);
void	ft_rotate_b(t_stack *a, t_stack *b, t_list *node);
char	**ft_split(char const *s, char c);
t_list	*ft_inject_node(t_stack *st, int val);
void	ft_errors(void);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
void	*malloc2(int size);
t_list	*ft_inject_node(t_stack *st, int val);
void	ft_remove_injection(t_stack *st, t_list *injected_node);
t_list	*ft_find_min_node(t_list *injected_node, int val);
void	ft_set_acnt(t_stack *a, t_list *b_node, int position);
void	ft_sort_in_a(t_stack *a, t_stack *b, t_list *node);
void	ft_switch_cases(t_stack *a, t_stack *b);
void	ft_case_three(t_stack *a, t_stack *b, int offset);
void	ft_case_four(t_stack *a, t_stack *b, int offset);
void	ft_case_five(t_stack *a, t_stack *b);

#endif
