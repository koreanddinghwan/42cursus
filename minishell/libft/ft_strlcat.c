/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:53:49 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 18:19:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cat(char *dest, char *src, t_size s, t_size dsize)
{
	int	c;

	c = 0;
	while ((src[c] && (dsize < s - 1)))
		dest[dsize++] = src[c++];
	dest[dsize] = '\0';
}

t_size	ft_strlcat(char *dest, char *src, t_size size)
{
	t_size		len_dest;
	t_size		len_src;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size > len_dest + 1)
		ft_cat(dest, src, size, len_dest);
	if (size <= len_dest)
		return (len_src + size);
	else
		return (len_dest + len_src);
}
