/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:24:39 by myukang           #+#    #+#             */
/*   Updated: 2022/03/28 23:13:39 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, t_size_t len)
{
	t_size_t		i;
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
