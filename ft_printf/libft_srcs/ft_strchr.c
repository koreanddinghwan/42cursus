/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 15:51:12 by myukang           #+#    #+#             */
/*   Updated: 2022/03/28 23:12:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		*p;
	t_size_t	size;
	t_size_t	i;

	p = 0;
	i = 0;
	size = ft_strlen((char *)s);
	while (i < size)
	{
		if (s[i] == (unsigned char)c)
		{
			p = (char *)(s + i);
			return (p);
		}
		i++;
	}
	if ((i == size) && (unsigned char)c == 0)
		return ((char *)(s + i));
	return (p);
}
