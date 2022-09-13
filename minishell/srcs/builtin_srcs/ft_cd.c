/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:16 by gyumpark          #+#    #+#             */
/*   Updated: 2022/07/02 12:13:30 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <errno.h>

char	*dup_buf(char *path, char *buf, char *home, char *old_save)
{
	if (!path)
		buf = ft_strdup(home);
	else if (!strcmp(path, "~"))
		buf = ft_strdup(home);
	else if (!strcmp(path, "-"))
	{
		if (!old_save)
			return (NULL);
		else
			buf = ft_strdup(old_save);
	}
	else
		buf = ft_strdup(path);
	return (buf);
}

void	append_oldpwd(t_data *data, t_envlst *node, t_envlst *last)
{
	if (ft_strcmp(last->key, "OLDPWD"))
	{
		node = ft_envlst_new("OLDPWD=OLDPWD");
		ft_envlst_pushback(&data->env_lst, node);
	}
}

void	change_env(t_data *data, char *oldpwd)
{
	t_envlst	*node;
	t_envlst	*last;
	char		*pwd;

	node = data->env_lst;
	last = ft_envlst_last(node);
	pwd = (char *)malloc(sizeof(char) * 256);
	if (!pwd)
		return ;
	pwd = getcwd(pwd, 256);
	while (node)
	{
		if (!ft_strncmp(node->key, "PWD", 3))
		{
			free(node->value);
			node->value = pwd;
			append_oldpwd(data, node, last);
		}
		if (!ft_strncmp(node->key, "OLDPWD", 6))
		{
			free(node->value);
			node->value = oldpwd;
		}
		node = node->next;
	}
}

void	chdir_env_free(t_data *data, char *buf, char *cur)
{
	if (chdir(buf) == -1)
	{
		if (buf)
		{
			ft_putstr_fd("mgyush > ", 2);
			ft_putstr_fd(buf, 2);
			ft_putstr_fd(": ", 2);
			ft_putendl_fd(strerror(errno), 2);
			free(cur);
		}
		else
		{
			if (!buf)
			{
				printf("mgyush: cd: OLDPWD not set\n");
				free(cur);
				return ;
			}
		}
		data->exit_status = EXECUTION_FAILURE;
	}
	else
		change_env(data, cur);
	free(buf);
}

void	ft_cd(t_data *data, char **path)
{
	t_envlst	*node;
	char		*buf;
	char		*home;
	char		*old_save;
	char		*cur;

	path++;
	node = data->env_lst;
	buf = 0;
	home = 0;
	old_save = 0;
	cur = (char *)malloc(sizeof(char) * 256);
	if (!cur)
		return ;
	cur = getcwd(cur, 256);
	while (node)
	{
		if (!ft_strcmp(node->key, "HOME"))
			home = node->value;
		if (!ft_strcmp(node->key, "OLDPWD"))
			old_save = node->value;
		node = node->next;
	}
	buf = dup_buf(*path, buf, home, old_save);
	chdir_env_free(data, buf, cur);
}
