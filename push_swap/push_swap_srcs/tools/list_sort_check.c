/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_sort_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 10:28:37 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:01:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	ascend_check(int *list, int count)
{
	int	ascend;
	int	i;

	ascend = ASD;
	i = 0;
	while (i < count - 1)
	{
		if (list[i] - list[i + 1] > 0)
			ascend = UNSORTED;
		i++;
	}
	return (ascend);
}

static int	descend_check(int *list, int count)
{
	int	descend;
	int	i;

	descend = DES;
	i = 0;
	while (i < count - 1)
	{
		if (list[i] - list[i + 1] < 0)
			descend = UNSORTED;
		i++;
	}
	return (descend);
}

int	list_sort_check(int *list, int count)
{
	int	ascend;
	int	descend;

	ascend = ascend_check(list, count);
	descend = descend_check(list, count);
	if (ascend)
		return (ASD);
	else if (descend)
		return (DES);
	else
		return (UNSORTED);
}
