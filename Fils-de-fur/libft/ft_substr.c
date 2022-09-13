/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:50:55 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 15:38:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, t_size len)
{
	char	*substr;
	t_size	size;

	if (!s)
		return (0);
	if (ft_strlen((char *)s) <= (t_size)start)
		return (ft_strdup(""));
	if (ft_strlen((char *)s) < len)
		size = ft_strlen((char *)s);
	else
		size = len;
	substr = ft_calloc(size + 1, sizeof(char));
	if (!substr)
		return (0);
	ft_strlcpy(substr, (char *)(s + start), size + 1);
	return (substr);
}
