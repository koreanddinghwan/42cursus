/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:44:20 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:41:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	swap_inst(t_dlst **lst)
{
	t_dlst	*a;
	t_dlst	*b;

	if (ft_dlst_size(*lst) <= 1)
		return ;
	else
	{
		a = ft_dlst_popfront(lst);
		b = ft_dlst_popfront(lst);
		ft_dlst_pushfront(lst, a);
		ft_dlst_pushfront(lst, b);
	}
}

void	swap(t_dlst **a, t_dlst **b, int flag)
{
	if (flag == SA)
	{
		ft_printf("sa\n");
		swap_inst(a);
	}
	else if (flag == SB)
	{
		ft_printf("sb\n");
		swap_inst(b);
	}
	else if (flag == SS)
	{
		ft_printf("ss\n");
		swap_inst(a);
		swap_inst(b);
	}
}
