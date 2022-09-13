/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:09:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 11:14:49 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	delete_multiple_tokens(t_data *data, enum e_word_type type)
{
	t_dlst	*tok_lst;
	t_dlst	*next;

	tok_lst = data->lexer_token_lst;
	while (tok_lst && get_ltok_type(tok_lst) == type)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
	}
}

char	*wget_join(t_dlst *cur, enum e_word_type type)
{
	char	*rtn;
	char	*ex;
	char	*buffer;

	rtn = ft_strdup("");
	if (type >= 8 && type <= 10)
		type = W_FILE;
	else if (type == 7)
		type = W_DELIMETER;
	while (cur && get_ltok_type(cur) == type)
	{
		ex = rtn;
		buffer = (get_ltok_cont(cur)->buffer);
		rtn = ft_strjoin(rtn, buffer);
		free(ex);
		cur = cur->next;
	}
	return (rtn);
}

t_dlst	*wget_startpoint(t_dlst *cur, enum e_word_type type)
{
	if (type >= 8 && type <= 10)
		type = W_FILE;
	else if (type == 7)
		type = W_DELIMETER;
	while (cur && get_ltok_type(cur) != type)
		cur = cur->next;
	return (cur);
}

int	get_offset(t_dlst *tok_lst, enum e_word_type type)
{
	int		offset;
	t_dlst	*cur;

	offset = 0;
	if (type >= 8 && type <= 10)
		type = W_FILE;
	else if (type == 7)
		type = W_DELIMETER;
	cur = tok_lst;
	while (cur && get_ltok_type(cur) != type)
	{
		cur = cur->next;
		offset++;
	}
	while (cur && get_ltok_type(cur) == type)
	{
		cur = cur->next;
		offset++;
	}
	return (offset);
}

t_cmd_cont	*init_cmd_cont(void)
{
	t_cmd_cont	*rtn;

	rtn = malloc(sizeof(t_cmd_cont) * 1);
	if (!rtn)
		return (NULL);
	rtn->cmd = NULL;
	rtn->args = NULL;
	rtn->iolst = NULL;
	rtn->infile = -1;
	rtn->outfile = -1;
	return (rtn);
}
