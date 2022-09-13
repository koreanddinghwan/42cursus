/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:38:17 by myukang           #+#    #+#             */
/*   Updated: 2022/04/22 17:45:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static void	ft_recur_nbr(long long n, int fd, int *rtn)
{
	if (n > 9)
	{
		ft_recur_nbr(n / 10, fd, rtn);
		*rtn += ft_putchar_fd(n % 10 + '0', fd);
	}
	else
	{
		*rtn += ft_putchar_fd(n % 10 + '0', fd);
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
		rtn += ft_putchar_fd('-', fd);
	}
	ft_recur_nbr(ln, fd, &rtn);
	return (rtn);
}
