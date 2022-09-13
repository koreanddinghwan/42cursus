/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:57:41 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 15:22:16 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>

# define INTMIN -2147483648
# define INTMAX 2147483647
# define ASD 1
# define DES -1
# define UNSORTED 0

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define DES -1
# define ASD 1
# define UNSORTED 0

# define CAB 2
# define ACB 3
# define BAC 4
# define BCA 5

# define VOID 0
# define AVOID 1

typedef struct s_chunk
{
	int	min;
	int	max;
	int	volume;
	int	min_index;
	int	max_index;
}	t_chunk;

int		init_argv(int ac, char ***av);
void	init_stack(int ac, char **av, t_dlst **a);
void	init_list(int **list, t_dlst **a, int c, char **av);
void	sort_stack(int *list, t_dlst **a, int sort_status, char **av);
void	descend_clear(t_dlst **a, t_dlst **b, int stack_count);
void	quick_sort_list(int *list, int start, int end);
int		list_sort_check(int *list, int count);
int		num_avail_check(char *str);
void	call_error(void);
void	call_error_av_stack_allclear(t_dlst **a, t_dlst **b,
			char **av, int *list);
void	call_error_av_stack_clear(t_dlst **a, char **av);
void	call_error_stack_clear(t_dlst **a, t_dlst **b);
void	call_error_clear(t_dlst **a);
void	quick_sort(int *list, int start, int end);
int		get_status(t_dlst *s);
void	hourglass_sort(int *list, t_dlst **a, t_dlst **b, t_dlst *chunk_lst);
t_dlst	*make_chunk(int chunk_amount, int *list, t_dlst **a, char **av);
void	chunk_min_max_init(t_dlst **chunk_lst, int *list, int chunk_amount);
void	rotate_after_pushb(t_dlst **a, t_dlst **b, int max, int next_max);
void	descend_sort(t_dlst **a, t_dlst **b, int stack_count);
int		get_status(t_dlst *s);
void	three_sort(t_dlst **a, t_dlst **b);
void	ten_sort(int *list, t_dlst **a, t_dlst **b, int stack_len);
void	hundred_sort(int *list, t_dlst **a, t_dlst **b, char **av);
void	five_hundred_sort(int *list, t_dlst **a, t_dlst **b, char **av);
void	push(t_dlst **a, t_dlst **b, int flag);
void	reverse_rotate(t_dlst **a, t_dlst **b, int flag);
void	rotate(t_dlst **a, t_dlst **b, int flag);
void	swap(t_dlst **a, t_dlst **b, int flag);
void	b_clear(int *list, t_dlst **a, t_dlst **b, int stack_count);
void	sort_top_three(t_dlst **a, t_dlst **b);

#endif
