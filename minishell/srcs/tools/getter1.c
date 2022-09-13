/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:28:39 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 11:32:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "getter.h"

t_lexer_token	*get_ltok_cont(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return ((t_lexer_token *)lst->content);
}

enum e_word_type	get_ltok_type(t_dlst *lst)
{
	return (get_ltok_cont(lst)->w_type);
}

t_cmd_cont	*get_cmd_cont(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return ((t_cmd_cont *)lst->content);
}

char	*get_cmd(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return ((get_cmd_cont(lst))->cmd);
}

char	**get_args(t_dlst *lst)
{
	if (!lst)
		return (NULL);
	return ((get_cmd_cont(lst))->args);
}
