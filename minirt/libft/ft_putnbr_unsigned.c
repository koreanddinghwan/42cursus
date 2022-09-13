/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 03:30:10 by myukang           #+#    #+#             */
/*   Updated: 2022/04/12 19:14:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"
#include <unistd.h>

static void	_ft_recur_nbr(long long n, int fd, int *rtn)
{
	if (n > 9)
	{
		_ft_recur_nbr(n / 10, fd, rtn);
		ft_putchar_fd(n % 10 + '0', fd);
		(*rtn)++;
	}
	else
	{
		ft_putchar_fd(n % 10 + '0', fd);
		(*rtn)++;
	}
}

int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	unsigned long long	ln;
	int					rtn;

	ln = n;
	rtn = 0;
	_ft_recur_nbr(ln, fd, &rtn);
	return (rtn);
}
