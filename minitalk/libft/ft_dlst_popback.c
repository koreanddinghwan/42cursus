/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_popback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:35:07 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 13:48:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_popback(t_dlst **dlst)
{
	t_dlst	*rtn;

	if (!(*dlst))
		return (0);
	rtn = ft_dlst_last((*dlst));
	if (rtn->back)
		rtn->back->next = 0;
	rtn->back = 0;
	return (rtn);
}
