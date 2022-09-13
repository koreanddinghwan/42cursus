/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:31:59 by myukang           #+#    #+#             */
/*   Updated: 2022/04/22 17:45:51 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	rtn;

	rtn = 0;
	if (s == 0)
	{
		return (write(1, "(null)", 6));
	}
	if (fd < 0)
		return (0);
	while (*s)
	{
		rtn += ft_putchar_fd(*(s++), fd);
	}
	return (rtn);
}
