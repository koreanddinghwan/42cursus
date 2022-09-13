/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:22:16 by myukang           #+#    #+#             */
/*   Updated: 2022/04/23 18:03:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_status(t_dlst *s)
{
	int	i;
	int	j;
	int	k;

	i = *(int *)s->content;
	s = s->next;
	j = *(int *)s->content;
	s = s->next;
	k = *(int *)s->content;
	if ((i > j) && (i > k) && (j < k))
		return (CAB);
	else if ((i < j) && (i < k) && (j > k))
		return (ACB);
	else if ((i > j) && (j < k) && (i < k))
		return (BAC);
	else if ((i < j) && (j > k) && (i > k))
		return (BCA);
	else if ((i > j) && (j > k) && (i > k))
		return (DES);
	else
		return (ASD);
}
