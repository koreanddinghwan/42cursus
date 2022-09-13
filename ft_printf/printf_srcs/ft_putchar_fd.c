/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:29:17 by myukang           #+#    #+#             */
/*   Updated: 2022/03/29 01:49:52 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write(fd, &c, 1);
	return (1);
}
