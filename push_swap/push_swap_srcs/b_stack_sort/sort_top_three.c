/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_top_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:11:07 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:13:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	des_sort(t_dlst **a, t_dlst **b)
{
	swap(a, b, SA);
	rotate(a, b, RA);
	swap(a, b, SA);
	push(a, b, PB);
	reverse_rotate(a, b, RRA);
	push(a, b, PA);
}

static void	bca_sort(t_dlst **a, t_dlst **b)
{
	rotate(a, b, RA);
	swap(a, b, SA);
	push(a, b, PB);
	reverse_rotate(a, b, RRA);
	push(a, b, PA);
}

static void	acb_sort(t_dlst **a, t_dlst **b)
{
	rotate(a, b, RA);
	swap(a, b, SA);
	reverse_rotate(a, b, RRA);
}

static void	cab_sort(t_dlst **a, t_dlst **b)
{
	swap(a, b, SA);
	rotate(a, b, RA);
	swap(a, b, SA);
	reverse_rotate(a, b, RRA);
}

void	sort_top_three(t_dlst **a, t_dlst **b)
{
	int	status;

	status = get_status(*a);
	if (status == CAB)
		cab_sort(a, b);
	else if (status == ACB)
		acb_sort(a, b);
	else if (status == BAC)
		swap(a, b, SA);
	else if (status == BCA)
		bca_sort(a, b);
	else if (status == DES)
		des_sort(a, b);
}
