/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 03:48:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 10:24:38 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	open_file(t_dlst *iolst, enum e_word_type type)
{
	int		fd;
	char	*path;

	path = get_io_cont(iolst)->filepath;
	if (type == W_APPENDING_TO)
		fd = open(path, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (type == W_REDIRECTION_OUTPUT)
		fd = open(path, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == W_REDIRECTION_INPUT)
		fd = open(path, O_RDONLY);
	else
		return (SUCESS);
	if (fd < 0)
		return (print_redir_error(path, strerror(errno)));
	get_io_cont(iolst)->fd = fd;
	return (SUCESS);
}

int	set_fd(t_dlst *iolst)
{
	int	status;

	status = SUCESS;
	while (iolst)
	{
		status = open_file(iolst, get_io_cont(iolst)->type);
		if (status == FAIL)
			return (FAIL);
		iolst = iolst->next;
	}
	return (SUCESS);
}

void	close_fd(t_data *data)
{
	t_dlst	*cmdlst;
	t_dlst	*iolst;

	cmdlst = data->cmd_lst;
	while (cmdlst)
	{
		iolst = (get_cmd_cont(cmdlst))->iolst;
		while (iolst)
		{
			if (get_io_cont(iolst)->fd != -1)
			{
				close(get_io_cont(iolst)->fd);
				get_io_cont(iolst)->fd = -1;
			}
			iolst = iolst->next;
		}
		cmdlst = cmdlst->next;
	}
}

int	set_last(t_dlst *iolst, enum e_word_type one, enum e_word_type two)
{
	int					last;
	enum e_word_type	type;

	last = -1;
	while (iolst)
	{
		type = get_io_cont(iolst)->type;
		if (type == one || type == two)
		{
			if (last != -1)
				close(last);
			last = get_io_cont(iolst)->fd;
		}
		iolst = iolst->next;
	}
	return (last);
}

int	set_redir(t_cmd_cont *cmd, t_data *data)
{
	t_dlst	*iolst;

	iolst = cmd->iolst;
	if (set_fd(iolst) == FAIL)
	{
		close_fd(data);
		return (FAIL);
	}
	cmd->infile = set_last(iolst, W_HERE_DOC, W_REDIRECTION_INPUT);
	cmd->outfile = set_last(iolst, W_APPENDING_TO, W_REDIRECTION_OUTPUT);
	return (SUCESS);
}
