/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:24:39 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 15:38:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, t_size len)
{
	t_size			i;
	unsigned char	*d;

	i = 0;
	d = b;
	while (i < len)
	{
		*(d + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
