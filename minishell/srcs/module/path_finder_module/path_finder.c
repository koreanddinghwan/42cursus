/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:27:24 by myukang           #+#    #+#             */
/*   Updated: 2022/06/29 12:20:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finder.h"

void	*find_env_key(t_envlst *envlst, char *key)
{
	char	*e_value;
	char	*e_key;

	while (envlst)
	{
		e_key = envlst->key;
		e_value = envlst->value;
		if (ft_strcmp(e_key, key) == 0)
			return (e_value);
		envlst = envlst->next;
	}
	return (NULL);
}

char	*cmdpath_finder(t_envlst *envlst, char *cmd)
{
	char	*rtn;

	rtn = NULL;
	if (exist_slash(cmd) == TRUE)
		return (cmd);
	else
	{
		rtn = check_envpath(find_env_key(envlst, "PATH"), cmd);
		if (rtn)
			return (rtn);
		else
			return (cmd);
	}
}

char	*iopath_finder(char *path, int type)
{
	char	*rtn;

	rtn = NULL;
	if (type == W_HERE_DOC)
		return (path);
	if (exist_slash(path) == TRUE)
		return (path);
	else
	{
		rtn = ft_strjoin("./", path);
		if (rtn)
		{
			free(path);
			return (rtn);
		}
		else
			return (path);
	}
}
