/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:38:15 by myukang           #+#    #+#             */
/*   Updated: 2022/03/25 19:40:42 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(t_size_t count, t_size_t size)
{
	void		*p;
	char		*s;
	t_size_t	i;

	p = malloc(size * count);
	if (!p)
		return (0);
	s = p;
	i = 0;
	while (i < count * size)
		s[i++] = 0;
	return (p);
}

size_t	ft_strlcpy(char *dest, char *src, t_size_t size)
{
	t_size_t	i;
	t_size_t	srcsize;

	srcsize = 0;
	while (src[srcsize])
		srcsize++;
	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && (i < size - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (srcsize);
}

char	*ft_strjoin(char *save, char *buffer, int *rd_rtn)
{
	t_size_t	size_save;
	t_size_t	size_buf;
	char		*joinstr;

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

char	*ft_strchr(const char *s, int c)
{
	t_size_t	size;
	t_size_t	i;

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

char	*ft_strndup(char *src, t_size_t n)
{
	char		*ptr;
	t_size_t	i;

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
