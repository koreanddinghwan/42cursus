/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:37:04 by myukang           #+#    #+#             */
/*   Updated: 2022/03/16 18:05:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*node;

	if (!lst || !f)
		return (0);
	node = ft_lstnew(f(lst->content));
	if (!node)
		return (0);
	start = node;
	lst = lst->next;
	while (lst != 0)
	{
		node->next = ft_lstnew(f(lst->content));
		if (!(node->next))
		{
			if (del)
				ft_lstclear(&start, del);
			return (0);
		}
		lst = lst->next;
		node = node->next;
	}
	return (start);
}
