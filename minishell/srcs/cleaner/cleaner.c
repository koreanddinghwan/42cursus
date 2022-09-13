/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:46:42 by myukang           #+#    #+#             */
/*   Updated: 2022/07/02 13:52:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cleaner.h"

void	lexer_tok_free(void *param)
{
	t_lexer_token	*cur;

	cur = param;
	if (!cur)
		return ;
	if (cur->buffer)
		free(cur->buffer);
	free(cur);
}

void	token_free(t_data *data)
{
	if (data->tok_buf)
	{
		free(data->tok_buf);
		data->tok_buf = NULL;
	}
	if (data->command)
	{
		free(data->command);
		data->command = NULL;
	}
}

void	lexer_free(t_data *data)
{
	token_free(data);
	if (data->lexer_token_lst)
	{
		ft_dlst_clear(&data->lexer_token_lst, lexer_tok_free);
		data->lexer_token_lst = NULL;
	}
}

void	cleaner(t_data *data)
{
	if (!data->cmd_lst)
		return ;
	if (data->tok_buf)
	{
		free(data->tok_buf);
		data->tok_buf = NULL;
	}
	ft_dlst_clear(&(data->cmd_lst), cmd_cont_free);
	data->cmd_lst = NULL;
	if (data->command)
	{
		free(data->command);
		data->command = NULL;
	}
}
