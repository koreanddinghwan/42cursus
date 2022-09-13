/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:34:59 by myukang           #+#    #+#             */
/*   Updated: 2022/06/17 20:55:58 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_size	ft_get_right(char *ds, char *set)
{
	t_size	size;
	char	*origin;

	size = 0;
	origin = ds;
	while (*ds)
		ds++;
	ds--;
	while (*ds)
	{
		if (ft_strchr(set, *ds))
			size++;
		else
			break ;
		if ((t_size)(ds) == (t_size)origin)
			break ;
		ds--;
	}
	return (size);
}

static t_size	ft_get_left(char *ds, char *set)
{
	t_size	size;

	size = 0;
	while (*ds)
	{
		if (ft_strchr(set, *ds))
			size++;
		else
			break ;
		ds++;
	}
	return (size);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	t_size	left;
	t_size	right;

	if (!s1 || !set)
		return (0);
	left = ft_get_left((char *)s1, (char *)set);
	right = ft_get_right((char *)s1, (char *)set);
	if (ft_strlen((char *)s1) == left + right)
		return (ft_strdup(""));
	if ((ft_strlen((char *)s1) == left) && (left == right))
		return (ft_strdup(""));
	result = ft_calloc((ft_strlen((char *)s1))
			- left - right + 1, sizeof(char));
	if (!result)
		return (0);
	ft_strlcpy(result, (char *)s1 + left,
		(ft_strlen((char *)s1)) - left - right + 1);
	return (result);
}
