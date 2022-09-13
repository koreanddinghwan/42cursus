/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:49 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 15:00:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	set_cmd(t_dlst *lst)
{
	t_lexer_token		*token;
	enum e_word_type	type;

	while (lst)
	{
		token = get_ltok_cont(lst);
		type = token->w_type;
		if (type == W_PIPE || type == W_SPACE)
			return ;
		else if (type == W_ARG)
			token->w_type = W_COMMAND;
		lst = lst->next;
	}
}

char	*make_cmd(t_data *data)
{
	t_dlst	*tok_lst;
	t_dlst	*next;
	char	*rtn;
	int		offset;

	tok_lst = data->lexer_token_lst;
	rtn = NULL;
	delete_multiple_tokens(data, W_SPACE);
	tok_lst = data->lexer_token_lst;
	set_cmd(tok_lst);
	offset = get_offset(tok_lst, W_COMMAND);
	tok_lst = wget_startpoint(tok_lst, W_COMMAND);
	if (tok_lst)
		rtn = wget_join(tok_lst, W_COMMAND);
	tok_lst = data->lexer_token_lst;
	while (tok_lst && offset + 1)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
		offset--;
	}
	return (rtn);
}
