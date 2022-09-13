/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 17:01:22 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 14:24:15 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lexer_token	*lexer_space_token(void)
{
	t_lexer_token	*rtn;

	rtn = ft_calloc(sizeof(t_lexer_token), 1);
	rtn->buf_len = 1;
	rtn->buffer = ft_calloc(sizeof(char), 2);
	rtn->buffer[0] = ' ';
	rtn->buffer[1] = '\0';
	rtn->w_type = W_SPACE;
	return (rtn);
}

void	lexer_add_nth(t_data *data)
{
	t_dlst	*lst;
	int		i;

	lst = data->lexer_token_lst;
	i = 0;
	while (lst)
	{
		get_ltok_cont(lst)->nth = i;
		lst = lst->next;
		i++;
	}
}
