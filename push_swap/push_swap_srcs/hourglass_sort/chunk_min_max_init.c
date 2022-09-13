/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_min_max_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 02:23:30 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:29:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	accumulated_volume(t_dlst *chunk, int index)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (chunk->back != 0)
		chunk = chunk->back;
	while (i <= index)
	{
		sum += ((t_chunk *)(chunk->content))->volume;
		i++;
		chunk = chunk->next;
	}
	return (sum);
}

static void	set_min_max(t_dlst *chunk, int chunk_i, int *list, int *list_index)
{
	int	min_value;
	int	max_value;

	min_value = list[*list_index];
	((t_chunk *)(chunk->content))->min = min_value;
	((t_chunk *)(chunk->content))->min_index = *list_index;
	while ((*list_index) <= accumulated_volume(chunk, chunk_i) - 1)
	{
		(*list_index)++;
	}
	(*list_index)--;
	max_value = list[(*list_index)];
	((t_chunk *)(chunk->content))->max = max_value;
	((t_chunk *)(chunk->content))->max_index = *list_index;
}

void	chunk_min_max_init(t_dlst **chunk_lst, int *list, int chunk_amount)
{
	int		chunk_index;
	int		list_index;
	t_dlst	*cur;

	chunk_index = 0;
	list_index = 0;
	cur = *chunk_lst;
	while (cur && (chunk_index < chunk_amount))
	{
		set_min_max(cur, chunk_index, list, &list_index);
		list_index++;
		chunk_index++;
		cur = cur->next;
	}
}
