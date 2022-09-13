/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:59:02 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 16:10:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	join_args(char **rtn, t_data *data, int count)
{
	int		i;
	t_dlst	*tok_lst;

	i = 1;
	tok_lst = data->lexer_token_lst;
	while (i < count - 1)
	{
		tok_lst = data->lexer_token_lst;
		if (get_ltok_type(tok_lst) == W_ARG)
		{
			rtn[i++] = wget_join(tok_lst, W_ARG);
			delete_multiple_tokens(data, W_ARG);
		}
		else if (get_ltok_type(tok_lst) == W_SPACE)
			delete_multiple_tokens(data, W_SPACE);
	}
}

int	get_args_count(t_dlst *tok_lst)
{
	int	i;

	i = 0;
	while (tok_lst)
	{
		if (get_ltok_type(tok_lst) == W_PIPE)
			return (i);
		else if (get_ltok_type(tok_lst) == W_ARG)
		{
			i++;
			while (tok_lst && get_ltok_type(tok_lst) == W_ARG)
				tok_lst = tok_lst->next;
		}
		else
			tok_lst = tok_lst->next;
	}
	return (i);
}

void	make_args(t_data *data, t_cmd_cont *cont)
{
	char	**rtn;
	int		count;
	char	*cmd;

	cmd = cont->cmd;
	if (cmd == NULL)
		return ;
	count = get_args_count(data->lexer_token_lst) + 2;
	rtn = malloc(sizeof(char *) * (count));
	rtn[0] = ft_strdup(cmd);
	rtn[count - 1] = NULL;
	delete_multiple_tokens(data, W_SPACE);
	join_args(rtn, data, count);
	delete_multiple_tokens(data, W_SPACE);
	delete_multiple_tokens(data, W_PIPE);
	cont->args = rtn;
}
