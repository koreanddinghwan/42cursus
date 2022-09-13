/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:33:46 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/30 13:39:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	execute_builtin(t_data *data, char *cmd, char **args)
{
	if (!cmd)
		return ;
	if (ft_strcmp(PWD, cmd) == 0)
		ft_pwd();
	if (ft_strcmp(EXPORT, cmd) == 0)
		ft_export(data, args);
	if (ft_strcmp(UNSET, cmd) == 0)
		ft_unset(data, args);
	if (ft_strcmp(S_ECHO, cmd) == 0)
		ft_echo(data, args);
	if (ft_strcmp(CD, cmd) == 0)
		ft_cd(data, args);
	if (ft_strcmp(EXIT, cmd) == 0)
		ft_exit(data, args);
	if (ft_strcmp(ENV, cmd) == 0)
		ft_env(data, args);
}

void	pipe_first(t_data *data, int i, int *fd[2])
{
	i = data->cmd_size - 1;
	while (i--)
	{
		if (i != 0 && data->cmd_size - 1 >= 2)
			close(fd[i][1]);
		close(fd[i][0]);
	}
	if (data->pipe_exist)
		dup2(fd[0][1], STDOUT_FILENO);
}

void	pipe_last(t_data *data, int i, int *fd[2])
{
	i = data->cmd_size - 1;
	while (i--)
	{
		if (i != (data->cmd_size - 2) && data->cmd_size - 1 >= 2)
			close(fd[i][0]);
		close(fd[i][1]);
	}
	dup2(fd[data->cmd_size - 2][0], STDIN_FILENO);
}

void	pipe_mid(t_data *data, int i, int *fd[2], int pipe_num)
{
	i = data->cmd_size - 1;
	while (i--)
	{
		if (i != data->cmd_size - 1 - (pipe_num))
			close(fd[i][1]);
		if (i != data->cmd_size - 1 - (pipe_num) - 1)
			close(fd[i][0]);
	}
	dup2(fd[data->cmd_size - 1 - (pipe_num) - 1][0], STDIN_FILENO);
	dup2(fd[data->cmd_size - 1 - (pipe_num)][1], STDOUT_FILENO);
}

void	execute_dup2(t_data *data, int i, int *fd[2], int pipe_num)
{
	if (pipe_num == data->cmd_size - 1)
		pipe_first(data, i, fd);
	else if (pipe_num == 0)
		pipe_last(data, i, fd);
	else
		pipe_mid(data, i, fd, pipe_num);
}
