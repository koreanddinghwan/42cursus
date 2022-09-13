/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hourglass_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:45:12 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:25:49 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	btop_bigger_than_bnext(t_dlst **a, t_dlst **b)
{
	t_dlst	*last;
	t_dlst	*cur;

	cur = *b;
	if (!cur || !(cur->next))
	{
		rotate(a, b, RA);
		return ;
	}
	last = ft_dlst_last(cur);
	if (*(int *)cur->content < *(int *)cur->next->content
		&& *(int *)cur->content > *(int *)last->content)
		rotate(a, b, RR);
	else
		rotate(a, b, RA);
}

static void	all_pb(t_dlst **a, t_dlst **b)
{
	while (*a)
		push(a, b, PB);
}

void	hourglass_sort(int *list, t_dlst **a, t_dlst **b, t_dlst *chunk_lst)
{
	int	max;
	int	next_max;

	while (chunk_lst->next != 0)
	{
		max = list[((t_chunk *)chunk_lst->content)->max_index];
		next_max = list[((t_chunk *)chunk_lst->next->content)->max_index];
		while (((t_chunk *)chunk_lst->content)->volume && chunk_lst->next)
		{
			if (*(int *)(*a)->content <= max)
			{
				push(a, b, PB);
				((t_chunk *)chunk_lst->content)->volume--;
			}
			else if (*(int *)(*a)->content <= next_max)
			{
				rotate_after_pushb(a, b, max, next_max);
				((t_chunk *)chunk_lst->next->content)->volume--;
			}
			else
				btop_bigger_than_bnext(a, b);
		}
		chunk_lst = chunk_lst->next;
	}
	all_pb(a, b);
}
