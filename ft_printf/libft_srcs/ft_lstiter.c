/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:26:10 by myukang           #+#    #+#             */
/*   Updated: 2022/03/11 17:25:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void*))
{
	t_list	*cur;

	if (!lst)
		return ;
	if (!f)
		return ;
	cur = lst;
	while (cur != 0)
	{
		f(cur->content);
		cur = cur->next;
	}
}
