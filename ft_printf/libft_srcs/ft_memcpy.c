/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:37:02 by myukang           #+#    #+#             */
/*   Updated: 2022/03/28 23:13:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, t_size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	t_size_t		i;

	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
