/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:58:18 by myukang           #+#    #+#             */
/*   Updated: 2022/04/30 22:08:59 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	call_error_free_list(char *str, t_dlst **pixel_list)
{
	ft_dlst_clear(pixel_list, free);
	ft_putstr_fd(str, 2);
	exit(1);
}

void	call_error(char	*str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
