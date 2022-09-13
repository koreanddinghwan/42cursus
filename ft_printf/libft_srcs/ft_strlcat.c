/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:53:49 by myukang           #+#    #+#             */
/*   Updated: 2022/03/27 14:16:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cat(char *dest, char *src, t_size_t s, t_size_t dsize)
{
	int	c;

	c = 0;
	while ((src[c] && (dsize < s - 1)))
		dest[dsize++] = src[c++];
	dest[dsize] = '\0';
}

t_size_t	ft_strlcat(char *dest, char *src, t_size_t size)
{
	t_size_t		i;
	t_size_t		len_dest;
	t_size_t		len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	if (size > len_dest + 1)
		ft_cat(dest, src, size, len_dest);
	if (size <= len_dest)
		return (len_src + size);
	else
		return (len_dest + len_src);
}
