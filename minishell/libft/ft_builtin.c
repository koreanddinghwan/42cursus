/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:09:14 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 14:21:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_envlst_size(t_envlst *envlst)
{
	int	size;

	size = 0;
	while (envlst)
	{
		size++;
		envlst = envlst->next;
	}
	return (size);
}

t_envlst	*ft_envlst_last(t_envlst *envlst)
{
	t_envlst	*cur;

	if (!envlst)
		return (0);
	cur = envlst;
	while (cur && cur->next != 0)
		cur = cur->next;
	return (cur);
}

void	ft_envlst_pushback(t_envlst **envlst, t_envlst *new)
{
	t_envlst	*last;

	last = ft_envlst_last(*envlst);
	if (last == 0)
	{
		*envlst = new;
		return ;
	}
	last->next = new;
	new->back = last;
}

t_envlst	*ft_envlst_new(void *c)
{
	t_envlst	*node;
	char		**split;

	node = ft_calloc(sizeof(t_envlst), 1);
	if (!node)
		return (0);
	split = ft_split((char *)c, '=');
	if (split[1] == (void *)0)
		split[1] = ft_strdup("");
	node->key = split[0];
	node->value = split[1];
	node->next = 0;
	node->back = 0;
	free(split);
	return (node);
}
