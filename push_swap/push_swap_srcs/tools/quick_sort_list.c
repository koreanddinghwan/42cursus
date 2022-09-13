/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:34:33 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 15:04:59 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	quick_swap(int *list, int i, int j, int pivot)
{
	int	t;

	if (i > j)
	{
		t = list[j];
		list[j] = list[pivot];
		list[pivot] = t;
	}
	else
	{
		t = list[j];
		list[j] = list[i];
		list[i] = t;
	}
}

void	quick_sort_list(int *list, int start, int end)
{
	int	pivot;
	int	i;
	int	j;

	if (start >= end)
		return ;
	pivot = start;
	i = pivot + 1;
	j = end;
	while (i <= j)
	{
		while ((i <= end) && (list[i] <= list[pivot]))
			i++;
		while ((j > start) && (list[j] >= list[pivot]))
			j--;
		quick_swap(list, i, j, pivot);
	}
	quick_sort_list(list, start, j - 1);
	quick_sort_list(list, j + 1, end);
}
