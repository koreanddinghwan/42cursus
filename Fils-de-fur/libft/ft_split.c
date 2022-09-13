/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:06:21 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 13:32:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_wd_cnt(char *str, char c)
{
	int	count;

	count = 0;
	if (c == 0)
		return (1);
	while (*str)
	{
		while (*str && (*str == c))
			str++;
		if (*str != 0)
		{
			count++;
			while (*str && (*str != c))
				str++;
		}
	}
	return (count);
}

static char	*ft_make_wd(char *str, char c, int	*alloc_err)
{
	int		i;
	char	*p;

	i = 0;
	while (str[i] && (str[i] != c))
		i++;
	p = ft_calloc(i + 1, sizeof(char));
	if (!p)
	{
		*alloc_err = 1;
		return (0);
	}
	ft_strlcpy(p, str, i + 1);
	return (p);
}

void	ft_freesplit(char ***s, int *p_index)
{
	char	**str;
	int		i;

	str = *s;
	i = 0;
	while (i < *p_index)
	{
		free(str[i++]);
	}
	free(str);
	*s = ft_calloc(sizeof(char *), 1);
	*p_index = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		p_index;
	int		alloc_err;

	if (!s)
		return (0);
	p = ft_calloc(ft_wd_cnt((char *)s, c) + 1, sizeof(char *));
	if (!p)
		return (0);
	p_index = 0;
	alloc_err = 0;
	while (*s && !alloc_err)
	{
		while (*s && (*s == c) && !alloc_err)
			s++;
		if (*s != 0)
			p[p_index++] = ft_make_wd((char *)s, c, &alloc_err);
		while (*s && !(*s == c) && !alloc_err)
			s++;
	}
	if (alloc_err)
		ft_freesplit(&p, &p_index);
	p[p_index] = 0;
	return (p);
}
