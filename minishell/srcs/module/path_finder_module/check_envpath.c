/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_envpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 00:41:58 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 20:41:35 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path_finder.h"

int	check_fs(char *path)
{
	struct stat	finfo;

	if (!path)
		return (0);
	if (stat(path, &finfo) < 0)
		return (0);
	return (isreg(finfo.st_mode) && isexec(finfo.st_mode));
}

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
	{
		free(splited[i]);
		i++;
	}
	free(splited);
}

char	*check_envpath(char *path, char *cmd)
{
	char	**splited;
	int		i;
	char	*joined;
	char	*ex;

	splited = ft_split(path, ':');
	if (!splited)
		return (NULL);
	i = 0;
	while (splited[i])
	{
		ex = ft_strjoin(splited[i], "/");
		joined = ft_strjoin(ex, cmd);
		free(ex);
		if (check_fs(joined))
		{
			free_splited(splited);
			free(cmd);
			return (joined);
		}
		free(joined);
		i++;
	}
	free_splited(splited);
	return (NULL);
}
