/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:44:56 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 21:00:44 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	cal_size(char *str, char *charset)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str && check_charset(*str, charset))
		{
			str++;
		}
		if (*str != '\0')
		{
			i += 1;
			while (*str && !check_charset(*str, charset))
				str++;
		}
	}
	return (i);
}

char	*make_str(char *str, int s, char *charset, int *alloc_error)
{
	char	*t;
	int		i;

	t = malloc(sizeof(char) * s + 1);
	if (!t)
	{
		*alloc_error = 1;
		return (0);
	}
	i = 0;
	while (*str && !check_charset(*str, charset))
	{
		t[i++] = *(str);
		str++;
	}
	t[i] = '\0';
	return (t);
}

int	str_size(char *str, char *charset)
{
	int	s;

	s = 0;
	if (*charset == 0)
	{
		while (*str)
		{
			s++;
			str++;
		}
		return (s);
	}
	while ((*str) && !check_charset(*(str + s), charset))
		s++;
	return (s);
}

char	**ft_split_charset(char *str, char *charset)
{
	char	**res;
	int		i;
	int		alloc_error;

	res = (char **)ft_calloc((cal_size(str, charset) + 1), sizeof(char *));
	if (!res)
		return ((void *)0);
	i = 0;
	alloc_error = 0;
	while (*str && !alloc_error)
	{
		while (*str && check_charset(*str, charset) && !alloc_error)
			str++;
		if (*str != '\0' && !alloc_error)
		{
			res[i++] = make_str(str, str_size(str, charset),
					charset, &alloc_error);
			while (*str && !check_charset(*str, charset) && !alloc_error)
				str++;
		}
	}
	if (alloc_error)
		ft_freesplit(&res, &i);
	res[i] = ((void *)0);
	return (res);
}
