/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:05:37 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 15:38:09 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	t_size	str_len;
	char	*joinstr;

	if (!s1 || !s2)
		return (0);
	str_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (str_len == 0)
		return (ft_strdup(""));
	joinstr = ft_calloc(str_len + 1, sizeof(char));
	if (!joinstr)
		return (0);
	ft_strlcpy(joinstr + ft_strlcpy(joinstr,
			(char *)s1, ft_strlen((char *)s1) + 1), (char *)s2, str_len + 1);
	return (joinstr);
}
