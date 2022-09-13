/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   descend_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:33:26 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:11:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	descend_sort(t_dlst **a, t_dlst **b, int stack_count)
{
	if (stack_count == 2)
		swap(a, b, SA);
	else if (stack_count == 3)
	{
		swap(a, b, SA);
		reverse_rotate(a, b, RRA);
	}
	else
	{
		push(a, b, PB);
		descend_sort(a, b, stack_count - 1);
		push(a, b, PA);
		rotate(a, b, RA);
	}
}
