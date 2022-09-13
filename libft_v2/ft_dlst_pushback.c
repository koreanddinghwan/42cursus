/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pushback.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:48:54 by myukang           #+#    #+#             */
/*   Updated: 2022/04/22 17:42:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_pushback(t_dlst **dlst, t_dlst *new)
{
	t_dlst	*last;

	last = ft_dlst_last(*dlst);
	if (last == 0)
	{
		*dlst = new;
		return ;
	}
	last->next = new;
	new->back = last;
}
