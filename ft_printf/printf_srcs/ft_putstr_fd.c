/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:31:59 by myukang           #+#    #+#             */
/*   Updated: 2022/03/29 01:55:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	rtn;

	rtn = 0;
	if (s == 0)
	{
		write(1, "(null)", 6);
		return (6);
	}
	if (fd < 0)
		return (0);
	while (*s)
	{
		ft_putchar_fd(*(s++), fd);
		rtn++;
	}
	return (rtn);
}
