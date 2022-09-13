/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:01:58 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 13:57:22 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_child(t_data *data, t_dlst *cmd, int *fd[2], int *pipe_num)
{
	int	status;
	int	i;

	status = 0;
	i = 0;
	if (set_redir(cmd->content, data) == FAIL)
		exit(1);
	if (get_infile(cmd) != -1)
		dup2(get_infile(cmd), STDIN_FILENO);
	if (get_outfile(cmd) != -1)
		dup2(get_outfile(cmd), STDOUT_FILENO);
	execute_dup2(data, i, fd, *pipe_num);
	if (check_builtin(get_cmd(cmd)))
		execute_builtin(data, get_cmd(cmd), get_args(cmd));
	else
	{
		if (execve(get_cmd(cmd), get_args(cmd), data->env) == -1)
			check_execve_error(cmd);
	}
	exit(status);
}

void	execute_pipe(t_data *data, t_dlst *cmd, int *pipe_num, int *fd[2])
{
	pid_t	g_pid;

	g_pid = fork();
	if (g_pid < 0)
		exit(1);
	if (g_pid == 0)
		execute_child(data, cmd, fd, &(*pipe_num));
}

void	close_pipe(t_data *data, int pipe, int *fd[2], int *status)
{
	int	i;

	while (pipe--)
	{
		close(fd[pipe][0]);
		close(fd[pipe][1]);
	}
	signal(SIGINT, SIG_IGN);
	while (wait(&(*status)) > 0)
		change_exitstatus(data, *status);
	signal(SIGINT, sigint_handler);
	i = 0;
	while (i < data->cmd_size - 1)
	{
		free(fd[i]);
		i++;
	}
	free(fd);
}

void	execute_cmd(t_data *data, t_dlst *cmd_lst, int *remain_pipe, int *fd[2])
{
	int	i;

	i = 0;
	while (cmd_lst)
	{
		if (!fork_builtin(get_cmd(cmd_lst))
			&& !data->pipe_exist && !get_io_list(cmd_lst))
			execute_builtin(data, get_cmd(cmd_lst), get_args(cmd_lst));
		else
		{
			if (*remain_pipe == data->cmd_size - 1)
			{
				while (data->cmd_size - 1)
				{
					pipe(fd[i]);
					if (data->cmd_size - 2 == i)
						break ;
					i++;
				}
			}
			execute_pipe(data, cmd_lst, &(*remain_pipe), fd);
		}
		cmd_lst = cmd_lst->next;
		(*remain_pipe)--;
	}
}

void	execute(t_data *data)
{
	t_dlst	*cmd_lst;
	int		remain_pipe;
	int		**fd;
	int		status;
	int		i;

	cmd_lst = data->cmd_lst;
	remain_pipe = data->cmd_size - 1;
	fd = (int **)malloc(sizeof(int *) * (data->cmd_size - 1));
	i = 0;
	while (i < data->cmd_size - 1)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	if (!fd)
		return ;
	if (remain_pipe == 0)
		data->pipe_exist = 0;
	else
		data->pipe_exist = 1;
	if (make_heredoc(data) == FAIL)
		return ;
	execute_cmd(data, cmd_lst, &remain_pipe, fd);
	close_pipe(data, data->cmd_size - 1, fd, &status);
}
