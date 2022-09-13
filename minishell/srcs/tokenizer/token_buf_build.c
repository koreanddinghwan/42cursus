/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_buf_build.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 20:22:29 by myukang           #+#    #+#             */
/*   Updated: 2022/07/02 13:50:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

void	case_quote(t_token *tok_buf, char c, int *state, int type)
{
	if (c == type)
	{
		tok_buf->type = type;
		*state = STATE_NORMAL;
	}
	else
		tok_buf->type = NORM;
}

void	fill_buf(t_token *tok_buf, char c, int *state)
{
	if (c == DQUO)
	{
		tok_buf->type = DQUO;
		*state = STATE_DQUOTE;
	}
	else if (c == SQUO)
	{
		tok_buf->type = SQUO;
		*state = STATE_SQUOTE;
	}
	else if (c == PIPE)
		tok_buf->type = PIPE;
	else if (c == LESSER)
		tok_buf->type = LESSER;
	else if (c == GREATER)
		tok_buf->type = GREATER;
	else if (c == SPC)
		tok_buf->type = SPC;
	else
		tok_buf->type = NORM;
}

void	make_token_buffer(t_token *tok_buf, char *str, int *state)
{
	while (*str)
	{
		tok_buf->c = *str;
		if (*state == STATE_NORMAL)
			fill_buf(tok_buf, *str, state);
		else if (*state == STATE_SQUOTE)
			case_quote(tok_buf, *str, state, SQUO);
		else if (*state == STATE_DQUOTE)
			case_quote(tok_buf, *str, state, DQUO);
		str++;
		tok_buf++;
	}
	tok_buf->type = END_C;
	tok_buf->c = '\0';
}

int	token_buf_build(t_data *data)
{
	int		state;
	t_token	*tok_buf;
	char	*str;

	state = STATE_NORMAL;
	tok_buf = data->tok_buf;
	str = data->command;
	while (*str == '\n')
		str++;
	if (!str || !tok_buf)
		return (FAIL);
	make_token_buffer(tok_buf, str, &state);
	if (state == STATE_DQUOTE || state == STATE_SQUOTE)
	{
		ft_putendl_fd("this shell does not support solo quotes", 2);
		data->exit_status = EX_BADSYNTAX;
		return (FAIL);
	}
	return (SUCESS);
}
