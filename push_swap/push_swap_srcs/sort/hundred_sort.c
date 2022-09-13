/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hundred_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:37:25 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 15:20:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	hundred_sort(int *list, t_dlst **a, t_dlst **b, char **av)
{
	t_dlst	*chunk_lst;
	int		chunk_amount;
	int		stack_len;

	stack_len = ft_dlst_size(*a);
	quick_sort_list(list, 0, stack_len - 1);
	chunk_amount = 7;
	chunk_lst = make_chunk(chunk_amount, list, a, av);
	chunk_min_max_init(&chunk_lst, list, chunk_amount);
	hourglass_sort(list, a, b, chunk_lst);
	b_clear(list, a, b, stack_len);
	ft_dlst_clear(&chunk_lst, free);
}
