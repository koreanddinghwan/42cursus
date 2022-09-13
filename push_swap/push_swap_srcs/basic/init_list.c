/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:09:16 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 14:13:40 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	init_list(int **list, t_dlst **a, int c, char **av)
{
	int		i;
	t_dlst	*cur;

	i = 0;
	cur = (*a);
	*list = ft_calloc(c, sizeof(int));
	if (!(*list))
		call_error_av_stack_clear(a, av);
	while (i < c)
	{
		(*list)[i] = *(int *)(cur->content);
		i++;
		cur = cur->next;
	}
}
