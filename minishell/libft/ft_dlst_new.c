/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 13:31:31 by myukang           #+#    #+#             */
/*   Updated: 2022/06/10 12:28:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlst	*ft_dlst_new(void *c)
{
	t_dlst	*node;

	node = malloc(1 * sizeof(t_dlst));
	if (!node)
		return (0);
	node->content = c;
	node->next = 0;
	node->back = 0;
	return (node);
}
