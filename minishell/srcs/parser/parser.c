/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:37:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 18:11:31 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * parser define the order of commands
 * */

#include "parser.h"

void	make_cmdcont(t_data *data)
{
	t_cmd_cont	*cmd_cont;
	int			n;

	n = 0;
	while (data->lexer_token_lst)
	{
		cmd_cont = init_cmd_cont();
		cmd_cont->iolst = make_iolst(data);
		cmd_cont->cmd = make_cmd(data);
		cmd_cont->cmdtype = get_cmdtype(cmd_cont->cmd);
		if (cmd_cont->cmdtype != E_BUILTIN)
			cmd_cont->cmd = cmdpath_finder(data->env_lst, cmd_cont->cmd);
		make_args(data, cmd_cont);
		cmd_cont->nth = n;
		ft_dlst_pushback(&data->cmd_lst, ft_dlst_new(cmd_cont));
		n++;
	}
}

void	parser(t_data *data)
{
	if (!data)
		return ;
	make_cmdcont(data);
	data->cmd_size = ft_dlst_size(data->cmd_lst);
}
