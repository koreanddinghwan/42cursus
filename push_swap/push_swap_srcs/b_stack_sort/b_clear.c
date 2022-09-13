/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:15:57 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:16:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	find_min_front(t_dlst *b, int min)
{
	int	c;

	c = 0;
	while (b)
	{
		if (*(int *)b->content >= min)
			break ;
		b = b->next;
		c++;
	}
	return (c);
}

static int	find_min_back(t_dlst *b, int min)
{
	int	c;

	c = 0;
	b = ft_dlst_last(b);
	while (b)
	{
		if (*(int *)b->content >= min)
			break ;
		b = b->back;
		c++;
	}
	return (c);
}

static int	get_rotate_dir_min(t_dlst **b, int min)
{
	int	front;
	int	back;

	front = find_min_front(*b, min);
	back = find_min_back(*b, min);
	if (front >= back)
		return (RRB);
	else
		return (RB);
}

static void	rotate_by_dir(t_dlst **a, t_dlst **b, int min)
{
	int	dir;

	dir = get_rotate_dir_min(b, min);
	if (dir == RB)
		rotate(a, b, RB);
	else
		reverse_rotate(a, b, RRB);
}

void	b_clear(int *list, t_dlst **a, t_dlst **b, int stack_count)
{
	int	list_idx;
	int	min;
	int	count;

	list_idx = stack_count - 1;
	while (list_idx - 2 >= 0 && *b)
	{
		min = list[list_idx - 2];
		count = 3;
		while (count)
		{
			while (*(int *)(*b)->content < min)
				rotate_by_dir(a, b, min);
			push(a, b, PA);
			count--;
			list_idx--;
		}
		sort_top_three(a, b);
	}
	while (*b)
		push(a, b, PA);
	sort_top_three(a, b);
}
