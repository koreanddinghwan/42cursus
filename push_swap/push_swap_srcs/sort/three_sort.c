/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:17:51 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:09:08 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	three_sort(t_dlst **a, t_dlst **b)
{
	int	status;

	status = get_status(*a);
	if (status == CAB)
		rotate(a, b, RA);
	else if (status == ACB)
	{
		reverse_rotate(a, b, RRA);
		swap(a, b, SA);
	}
	else if (status == BAC)
		swap(a, b, SA);
	else if (status == BCA)
		reverse_rotate(a, b, RRA);
	else if (status == DES)
		descend_sort(a, b, 3);
}
