/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 21:31:32 by myukang           #+#    #+#             */
/*   Updated: 2022/03/11 12:08:30 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_caldigit(long n)
{
	int	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	ln;
	char		*p;
	int			size;

	ln = n;
	size = ft_caldigit(ln) + 1 + (ln < 0);
	p = ft_calloc(size, sizeof(char));
	if (!p)
		return (0);
	p[--size] = 0;
	if (ln < 0)
	{
		p[0] = '-';
		ln *= -1;
	}
	size--;
	while (size >= (n < 0))
	{
		p[size--] = ln % 10 + '0';
		ln /= 10;
	}
	return (p);
}
