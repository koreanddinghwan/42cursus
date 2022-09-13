/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 01:16:56 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 14:23:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ascend_clear(t_dlst **a, t_dlst **b)
{
	while (*b)
	{
		push(a, b, PA);
	}
}

static int	find_stack_idx(int value, t_dlst *a)
{
	int	c;

	c = 0;
	while (a)
	{
		if (*(int *)a->content == value)
			break ;
		a = a->next;
		c++;
	}
	return (c);
}

static void	find_value_push_instack(t_dlst **a, t_dlst **b, int value, int flag)
{
	while (*((int *)(*a)->content) != value)
	{
		if (flag == RA)
			rotate(a, b, flag);
		else
			reverse_rotate(a, b, flag);
	}
	push(a, b, PB);
}

void	ten_sort(int *list, t_dlst **a, t_dlst **b, int stack_len)
{
	int	i;
	int	stack_value_idx;
	int	stack_index;

	i = 0;
	quick_sort_list(list, 0, stack_len - 1);
	stack_index = stack_len;
	while (i < stack_index)
	{
		if (stack_len == 3)
		{
			three_sort(a, b);
			ascend_clear(a, b);
			return ;
		}	
		stack_value_idx = find_stack_idx(list[i], *a);
		if (stack_len / 2 < stack_value_idx)
			find_value_push_instack(a, b, list[i], RRA);
		else
			find_value_push_instack(a, b, list[i], RA);
		stack_len--;
		i++;
	}
}
