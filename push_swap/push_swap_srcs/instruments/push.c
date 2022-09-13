/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:44:13 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:37:58 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	push_from_to(t_dlst **from, t_dlst **to)
{
	t_dlst	*t;

	t = 0;
	if (*from == 0)
		return ;
	else
	{
		t = ft_dlst_popfront(from);
		ft_dlst_pushfront(to, t);
	}
}

void	push(t_dlst **a, t_dlst **b, int flag)
{
	if (flag == PA)
	{
		ft_printf("pa\n");
		push_from_to(b, a);
	}
	else
	{
		ft_printf("pb\n");
		push_from_to(a, b);
	}
}
