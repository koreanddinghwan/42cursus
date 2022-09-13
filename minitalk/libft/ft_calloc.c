/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:34:36 by myukang           #+#    #+#             */
/*   Updated: 2022/04/18 18:20:07 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(t_size count, t_size size)
{
	void	*p;

	p = malloc(size * count);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return (p);
}
