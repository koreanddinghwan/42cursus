/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:15:20 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 14:40:44 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_stack(int *list, t_dlst **a, int sort_status, char **av)
{
	int		size;
	t_dlst	*b;

	size = ft_dlst_size(*a);
	b = 0;
	if (sort_status == ASD)
		return ;
	else if (sort_status == DES)
		descend_sort(a, &b, size);
	else if (size == 3)
		three_sort(a, &b);
	else if (size <= 50)
		ten_sort(list, a, &b, size);
	else if (size <= 200)
		hundred_sort(list, a, &b, av);
	else
		five_hundred_sort(list, a, &b, av);
}
