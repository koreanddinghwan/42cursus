/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 04:09:13 by myukang           #+#    #+#             */
/*   Updated: 2022/04/12 19:12:34 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static void	ft_recur_pointer(unsigned long long p, int *rtn)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (p > 15)
	{
		ft_recur_pointer(p / 16, rtn);
		ft_putchar_fd(hex[p % 16], 1);
		(*rtn)++;
	}
	else
	{
		ft_putchar_fd(hex[p % 16], 1);
		(*rtn)++;
	}
}

int	ft_print_pointer(void *p)
{
	int					rtn;
	unsigned long long	ull;
	long long			ll;

	rtn = 0;
	ull = (unsigned long long)p;
	ll = (long long)p;
	if (ll == -1)
	{
		ft_putstr_fd("0xffffffffffffffff", 1);
		return (18);
	}
	rtn += ft_putstr_fd("0x", 1);
	ft_recur_pointer(ull, &rtn);
	return (rtn);
}
