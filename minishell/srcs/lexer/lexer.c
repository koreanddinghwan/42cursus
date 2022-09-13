/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:27:29 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 10:09:56 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

void	cleanup_routine(t_data *data, t_token **tok_buf, int *space_add)
{
	int				i;
	t_lexer_token	*l_tok;

	*space_add = 0;
	i = 0;
	l_tok = lexer_token_init(*tok_buf);
	ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
	while (i < l_tok->buf_len && (*tok_buf)->type != END_C)
	{
		(*tok_buf)++;
		i++;
	}
}

void	lexer_token_lst_init(t_data *data)
{
	t_token			*tok_buf;
	t_lexer_token	*l_tok;
	int				space_add;

	tok_buf = data->tok_buf;
	space_add = 0;
	while (tok_buf->type != END_C)
	{
		if (tok_buf->type == SPC && space_add == 1)
		{
			tok_buf++;
			continue ;
		}
		else if (tok_buf->type == SPC && space_add == 0)
		{
			l_tok = lexer_space_token();
			ft_dlst_pushback(&data->lexer_token_lst, ft_dlst_new(l_tok));
			tok_buf++;
			space_add = 1;
			continue ;
		}
		cleanup_routine(data, &tok_buf, &space_add);
	}
}

void	set_clobber(t_data *data, t_dlst *lst)
{
	t_dlst	*next;
	char	*buffer;

	while (lst)
	{
		if (lst && get_ltok_type(lst) == W_REDIRECTION_OUTPUT)
		{
			next = lst->next;
			if (next)
			{
				buffer = get_ltok_cont(lst)->buffer;
				if (ft_strcmp("|", buffer) == 0)
				{
					ft_dlst_delete(next,
						&data->lexer_token_lst, lexer_tok_free);
					lst = data->lexer_token_lst;
					continue ;
				}
			}
		}
		lst = lst->next;
	}
}

int	lexer(t_data *data)
{
	lexer_token_lst_init(data);
	set_clobber(data, data->lexer_token_lst);
	if (syntax_analyzer(data) == FAIL)
		return (FAIL);
	lexer_w_converter(data);
	replacer(data);
	lexer_add_nth(data);
	return (SUCESS);
}
