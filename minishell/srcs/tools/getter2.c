/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 20:48:50 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 16:45:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getter.h"

t_io_cont	*get_io_cont(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return ((t_io_cont *)lst->content);
}

t_dlst	*get_io_list(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return (get_cmd_cont(lst)->iolst);
}

int	get_infile(t_dlst *lst)
{
	return (get_cmd_cont(lst)->infile);
}

int	get_outfile(t_dlst *lst)
{
	return (get_cmd_cont(lst)->outfile);
}

char	*get_tmpname(t_dlst *iolst)
{
	return (get_io_cont(iolst)->tmpname);
}
