/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:04:36 by myukang           #+#    #+#             */
/*   Updated: 2022/07/02 14:19:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.h"

char	*get_replaced(t_data *data, char *str)
{
	char	*rtn;
	int		len;

	len = get_replaced_len(str, data);
	if (len == 0)
		return (NULL);
	rtn = malloc(sizeof(char) * (len + 1));
	if (!rtn)
	{
		free(str);
		return (0);
	}
	cpy_replaced(rtn, str, data, len);
	free(str);
	return (rtn);
}

void	replacer_exec(t_data *data, t_dlst *tok_lst)
{
	char	*buffer;

	buffer = get_ltok_cont(tok_lst)->buffer;
	if ((buffer[0] == '\'' || buffer[0] == '\"')
		&& get_ltok_type(tok_lst) == W_DELIMETER)
	{
		(get_ltok_cont(tok_lst))->buffer = ft_strtrim(buffer, "\'\"");
		free(buffer);
		return ;
	}
	if (buffer[0] == '\'')
	{
		(get_ltok_cont(tok_lst))->buffer = ft_strtrim(buffer, "\'");
		free(buffer);
	}
	else
	{
		(get_ltok_cont(tok_lst))->buffer = ft_strtrim(buffer, "\"");
		free(buffer);
		buffer = (get_ltok_cont(tok_lst)->buffer);
		(get_ltok_cont(tok_lst))->buffer = get_replaced(data, buffer);
	}
}

void	replacer(t_data *data)
{
	t_dlst	*tok_lst;

	tok_lst = data->lexer_token_lst;
	while (tok_lst)
	{
		if (!(get_ltok_type(tok_lst) == W_SPACE))
			replacer_exec(data, tok_lst);
		tok_lst = tok_lst->next;
	}
}
