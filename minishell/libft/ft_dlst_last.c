/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:36:59 by myukang           #+#    #+#             */
/*   Updated: 2022/06/19 19:32:47 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_last(t_dlst *dlst)
{
	t_dlst	*cur;

	if (!dlst)
		return (0);
	cur = dlst;
	while (cur && cur->next != 0)
		cur = cur->next;
	return (cur);
}
