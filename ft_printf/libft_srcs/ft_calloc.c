/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:34:36 by myukang           #+#    #+#             */
/*   Updated: 2022/03/27 14:09:49 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(t_size_t count, t_size_t size)
{
	void		*p;
	t_size_t	i;

	p = malloc(size * count);
	if (!p)
		return (0);
	i = 0;
	ft_bzero(p, count * size);
	return (p);
}
