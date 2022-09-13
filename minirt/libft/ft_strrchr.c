/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:31:46 by myukang           #+#    #+#             */
/*   Updated: 2022/03/12 15:21:54 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		size;

	p = 0;
	size = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)(s + size));
	while (size-- > 0)
	{
		if (s[size] == (char)c)
		{
			p = (char *)(s + size);
			return (p);
		}
	}
	return (p);
}
