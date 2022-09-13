/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_after_pushb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 15:27:03 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:36:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	atop_is_in_range(t_dlst **a, int max, int next_max)
{
	int	value;

	value = *(int *)(*a)->content;
	if (value <= max || value <= next_max)
		return (1);
	else
		return (0);
}

void	rotate_after_pushb(t_dlst **a, t_dlst **b, int max, int next_max)
{
	push(a, b, PB);
	if (atop_is_in_range(a, max, next_max))
		rotate(a, b, RB);
	else
		rotate(a, b, RR);
}
