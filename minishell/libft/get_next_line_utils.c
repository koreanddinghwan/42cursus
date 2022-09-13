/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:38:15 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 17:07:40 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnljoin(char *save, char *buffer, int *rd_rtn)
{
	t_size	size_save;
	t_size	size_buf;
	char	*joinstr;

	if (!buffer)
		return (0);
	if (!save)
		save = ft_strndup("", 1);
	size_save = ft_strlen(save);
	size_buf = ft_strlen(buffer);
	joinstr = ft_calloc((size_save + size_buf + 1), sizeof(char));
	if (!joinstr)
	{
		free((void *)save);
		*rd_rtn = -1;
		return (0);
	}
	ft_strlcpy(joinstr + ft_strlcpy(joinstr,
			save, size_save + 1), buffer, size_save + size_buf + 1);
	free((void *)save);
	return (joinstr);
}

char	*ft_gnlchr(const char *s, int c)
{
	t_size	size;
	t_size	i;

	if (!s)
		return (0);
	size = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)(s + size));
	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strndup(char *src, t_size n)
{
	char	*ptr;
	t_size	i;

	ptr = ft_calloc(sizeof(char), (n + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (src[i] && (i < n))
	{
		ptr[i] = src[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
