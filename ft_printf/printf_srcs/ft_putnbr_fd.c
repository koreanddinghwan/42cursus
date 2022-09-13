/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:38:17 by myukang           #+#    #+#             */
/*   Updated: 2022/03/29 01:49:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <unistd.h>

static void	ft_recur_nbr(long long n, int fd, int *rtn)
{
	if (n > 9)
	{
		ft_recur_nbr(n / 10, fd, rtn);
		ft_putchar_fd(n % 10 + '0', fd);
		(*rtn)++;
	}
	else
	{
		ft_putchar_fd(n % 10 + '0', fd);
		(*rtn)++;
	}
}

int	ft_putnbr_fd(int n, int fd)
{
	long long	ln;
	int			rtn;

	ln = n;
	rtn = 0;
	if (ln < 0)
	{
		ln *= -1;
		ft_putchar_fd('-', fd);
		rtn++;
	}
	ft_recur_nbr(ln, fd, &rtn);
	return (rtn);
}
