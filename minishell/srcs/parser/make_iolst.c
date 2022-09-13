/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_iolst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:02:31 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 20:29:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_redirection(t_dlst *tok_lst)
{
	while (tok_lst)
	{
		if (get_ltok_type(tok_lst) >= 7
			&& get_ltok_type(tok_lst) <= 10)
			return (1);
		if (get_ltok_type(tok_lst) == W_PIPE)
			return (0);
		tok_lst = tok_lst->next;
	}
	return (0);
}

void	token_delete(t_data *data, t_dlst *tok_lst, int offset)
{
	t_dlst		*next;

	while (tok_lst && offset)
	{
		next = tok_lst->next;
		ft_dlst_delete(tok_lst, &data->lexer_token_lst, lexer_tok_free);
		tok_lst = next;
		offset--;
	}
}

t_io_cont	*make_io_cont(t_data *data, t_dlst *tok_lst, enum e_word_type type)
{
	t_io_cont	*rtn;
	t_dlst		*cur;
	int			offset;

	rtn = NULL;
	cur = tok_lst;
	offset = get_offset(cur, type);
	cur = wget_startpoint(cur, type);
	if (cur)
	{
		rtn = malloc(sizeof(t_io_cont) * 1);
		if (!rtn)
			return (NULL);
		rtn->filepath = iopath_finder(wget_join(cur, type), type);
		rtn->type = type;
		rtn->tmpname = NULL;
		rtn->fd = -1;
	}
	token_delete(data, tok_lst, offset);
	return (rtn);
}

t_dlst	*make_iolst(t_data *data)
{
	t_dlst		*rtn;
	t_dlst		*tok_lst;
	t_io_cont	*new;

	rtn = NULL;
	delete_multiple_tokens(data, W_SPACE);
	tok_lst = data->lexer_token_lst;
	while (check_redirection(tok_lst))
	{
		while (tok_lst && (get_ltok_type(tok_lst) < 7
				|| get_ltok_type(tok_lst) > 10))
			tok_lst = tok_lst->next;
		if (tok_lst)
		{
			new = make_io_cont(data, tok_lst, get_ltok_type(tok_lst));
			if (new)
				ft_dlst_pushback(&rtn, ft_dlst_new(new));
			tok_lst = data->lexer_token_lst;
		}
	}
	return (rtn);
}
