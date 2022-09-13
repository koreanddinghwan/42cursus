/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:44:18 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:37:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotation(t_dlst **lst)
{
	t_dlst	*front;

	if (ft_dlst_size(*lst) <= 1)
		return ;
	else
	{
		front = ft_dlst_popfront(lst);
		ft_dlst_pushback(lst, front);
	}
}

void	rotate(t_dlst **a, t_dlst **b, int flag)
{
	if (flag == RA)
	{
		ft_printf("ra\n");
		rotation(a);
	}
	else if (flag == RB)
	{
		ft_printf("rb\n");
		rotation(b);
	}
	else
	{
		ft_printf("rr\n");
		rotation(a);
		rotation(b);
	}
}
