/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_popfront.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:41:25 by myukang           #+#    #+#             */
/*   Updated: 2022/04/22 17:42:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_popfront(t_dlst **dlst)
{
	t_dlst	*rtn;

	if (!(*dlst))
		return (0);
	rtn = (*dlst);
	*dlst = (*dlst)->next;
	rtn->next = 0;
	if (*dlst)
		(*dlst)->back = 0;
	return (rtn);
}
