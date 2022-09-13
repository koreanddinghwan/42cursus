/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envkey.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:45:57 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 11:17:02 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	set_env_lst(t_data *data, char **envp)
{
	t_envlst	*node;

	while (*envp)
	{
		node = ft_envlst_new(*envp);
		if (!node)
			return ;
		if (!ft_strcmp(node->key, "OLDPWD"))
		{
			envp++;
			free(node->key);
			free(node->value);
			free(node);
		}
		else
			ft_envlst_pushback(&data->env_lst, node);
		envp++;
	}
	data->env_size = ft_envlst_size(data->env_lst);
}

void	set_env_arr(t_data *data)
{
	t_envlst	*node;
	char		*buffer;
	char		*ex;
	int			i;

	node = data->env_lst;
	data->env = (char **)malloc(sizeof(char *) * (data->env_size +1));
	i = 0;
	if (!data->env)
		return ;
	while (node)
	{
		buffer = ft_strjoin(node->key, "=");
		ex = buffer;
		buffer = ft_strjoin(ex, node->value);
		free(ex);
		data->env[i++] = buffer;
		node = node->next;
	}
	data->env[i] = 0;
}
