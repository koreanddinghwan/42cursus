/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 00:13:46 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 18:16:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"
#include <readline/readline.h>
#include <readline/history.h>

int	exec_heredoc(t_data *data, t_dlst *iolst)
{
	int		fd;
	char	*input;

	fd = open(get_tmpname(iolst), O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		return (FAIL);
	while (1)
	{
		input = readline("> ");
		if (!input || ft_strcmp((get_io_cont(iolst))->filepath, input) == 0)
		{
			free(input);
			break ;
		}
		write_free_strings(data, input, fd);
	}
	close(fd);
	return (SUCESS);
}

int	set_heredoc_cont(t_dlst *iolst, t_data *data, int i)
{
	char	*index;

	index = ft_itoa(i);
	(get_io_cont(iolst))->tmpname = ft_strjoin("/tmp/.temp", index);
	free(index);
	if (exec_heredoc(data, iolst) == FAIL)
		return (FAIL);
	(get_io_cont(iolst))->fd = open((get_io_cont(iolst))->tmpname, O_RDONLY);
	return (SUCESS);
}

int	set_heredoc(t_cmd_cont *cmd, t_data *data)
{
	t_dlst	*iolst;
	int		i;
	int		num;

	num = set_heredocnum(cmd->iolst);
	iolst = cmd->iolst;
	i = 0;
	if (num)
	{
		while (iolst)
		{
			if ((get_io_cont(iolst))->type == W_HERE_DOC)
			{
				if (set_heredoc_cont(iolst, data, i++) == FAIL)
					return (FAIL);
			}
			iolst = iolst->next;
		}
	}
	return (SUCESS);
}

int	make_heredoc(t_data *data)
{
	t_dlst		*cmdlst;
	t_cmd_cont	*cmd;

	cmdlst = data->cmd_lst;
	while (cmdlst)
	{
		cmd = get_cmd_cont(cmdlst);
		if (set_heredoc(cmd, data) == FAIL)
		{
			close_fd(data);
			return (FAIL);
		}
		cmdlst = cmdlst->next;
	}
	return (SUCESS);
}
