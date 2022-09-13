/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 08:01:51 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 14:03:59 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	volume_init(int dummy_cnt, int stk_cnt, int chunk_amt, t_chunk *new)
{
	if (dummy_cnt > 0 && (stk_cnt % chunk_amt))
		new->volume = (stk_cnt / chunk_amt) + 1;
	else
		new->volume = stk_cnt / chunk_amt;
}

t_dlst	*make_chunk(int chunk_amount, int *list, t_dlst **a, char **av)
{
	int			dummy_count;
	int			chunk_index;
	t_dlst		*chunk_lst;
	t_chunk		*new;

	dummy_count = ft_dlst_size(*a) % chunk_amount;
	chunk_lst = 0;
	chunk_index = 0;
	while (chunk_index < chunk_amount)
	{
		new = ft_calloc(1, sizeof(t_chunk));
		if (!new)
			call_error_av_stack_allclear(a, &chunk_lst, av, list);
		ft_dlst_pushback(&chunk_lst, ft_dlst_new((void *)new));
		volume_init(dummy_count, ft_dlst_size(*a), chunk_amount, new);
		chunk_index++;
		dummy_count--;
	}
	return (chunk_lst);
}
