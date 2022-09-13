/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delone.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:33:47 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 13:59:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlst_delone(t_dlst *dlst, void (*del)(void *))
{
	if (!dlst)
		return ;
	if (!del)
		return ;
	if (dlst->content)
		del(dlst->content);
	free(dlst);
}
