/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_token_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 19:12:13 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 10:10:33 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int	lexer_get_len_lg(t_token *tok_buf, enum e_char_type compare)
{
	if ((tok_buf + 1)->type == compare)
		return (2);
	else
		return (1);
}

int	lexer_get_len_quotes(t_token *tok_buf, enum e_char_type compare)
{
	int	size;

	size = 0;
	if ((tok_buf + 1)->type == NORM)
	{
		tok_buf++;
		size++;
		while (tok_buf->type == NORM)
		{
			size++;
			tok_buf++;
		}
		if (tok_buf->type == compare)
			size++;
		return (size);
	}
	else if ((tok_buf + 1)->type == compare)
		return (2);
	else
		return (1);
}

int	lexer_get_buff_len(t_token *tok_buf)
{
	int	size;

	size = 0;
	if (tok_buf->type == PIPE)
		return (1);
	else if (tok_buf->type == LESSER)
		return (lexer_get_len_lg(tok_buf, LESSER));
	else if (tok_buf->type == GREATER)
		return (lexer_get_len_lg(tok_buf, GREATER));
	else if (tok_buf->type == NORM)
	{
		while (tok_buf->type == NORM)
		{
			size++;
			tok_buf++;
		}
		return (size);
	}
	else if (tok_buf->type == DQUO)
		return (lexer_get_len_quotes(tok_buf, DQUO));
	else if (tok_buf->type == SQUO)
		return (lexer_get_len_quotes(tok_buf, SQUO));
	return (0);
}

void	lexer_cpy_buf(t_lexer_token *rtn, t_token *tok_buf)
{
	int	i;

	if (!rtn || !tok_buf)
		return ;
	i = 0;
	while (tok_buf != END_C && i < rtn->buf_len)
	{
		(rtn->buffer)[i] = tok_buf->c;
		tok_buf++;
		i++;
	}
	(rtn->buffer)[i] = 0;
}

t_lexer_token	*lexer_token_init(t_token *tok_buf)
{
	t_lexer_token	*rtn;

	if (!tok_buf)
		return (0);
	rtn = ft_calloc(sizeof(t_lexer_token), 1);
	rtn->buf_len = lexer_get_buff_len(tok_buf);
	rtn->buffer = ft_calloc(sizeof(char), rtn->buf_len + 1);
	lexer_cpy_buf(rtn, tok_buf);
	lexer_decide_w_type(rtn);
	return (rtn);
}
