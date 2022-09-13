/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_pushfront.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:51:15 by myukang           #+#    #+#             */
/*   Updated: 2022/04/22 17:42:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_pushfront(t_dlst **dlst, t_dlst *new)
{
	if (*dlst == 0)
	{
		*dlst = new;
		return ;
	}
	new->next = *dlst;
	if (*dlst)
		(*dlst)->back = new;
	(*dlst) = new;
}
