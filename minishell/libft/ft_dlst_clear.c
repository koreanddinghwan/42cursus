/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 14:32:33 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 14:45:08 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_clear(t_dlst **dlst, void (*del)(void *))
{
	t_dlst	*cur;
	t_dlst	*next;

	if (!dlst || !del)
		return ;
	cur = *dlst;
	next = 0;
	while (cur != 0)
	{
		next = cur->next;
		ft_dlst_delone(cur, del);
		cur = next;
	}
	*dlst = (void *)0;
}
