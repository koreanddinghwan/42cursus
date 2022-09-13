/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:44:16 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:38:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rotation(t_dlst **lst)
{
	t_dlst	*last;

	if (ft_dlst_size(*lst) <= 1)
		return ;
	else
	{
		last = ft_dlst_popback(lst);
		ft_dlst_pushfront(lst, last);
	}
}

void	reverse_rotate(t_dlst **a, t_dlst **b, int flag)
{
	if (flag == RRA)
	{
		ft_printf("rra\n");
		rotation(a);
	}
	else if (flag == RRB)
	{
		ft_printf("rrb\n");
		rotation(b);
	}
	else
	{
		ft_printf("rrr\n");
		rotation(a);
		rotation(b);
	}
}
