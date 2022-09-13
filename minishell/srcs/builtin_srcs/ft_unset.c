/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:52 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/30 15:08:44 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	delete_env_lst(t_data *data, char *args)
{
	t_envlst	*next;
	t_envlst	*back;
	t_envlst	*cur;

	cur = data->env_lst;
	while (cur)
	{
		next = cur->next;
		back = cur->back;
		if (ft_strcmp(cur->key, args) == 0)
		{
			if (next)
				next->back = back;
			if (back)
				back->next = next;
			else
				data->env_lst = next;
			free(cur->key);
			free(cur->value);
			free(cur);
		}
		cur = next;
	}
	free(args);
}

int	ft_getcharindex(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			return (i);
		i++;
		str++;
	}
	return (i);
}

void	ft_unset(t_data *data, char **args)
{
	args++;
	if (!*args)
		return ;
	while (*args)
	{
		if ((!ft_isalpha(**args)
				&& !ft_isunder(**args)) || ft_strchr(*args, '='))
		{		
			ft_putstr_fd("mgyush > unset: `", 2);
			ft_putstr_fd(*args, 2);
			ft_putendl_fd("\': not a valid identifier", 2);
			data->exit_status = EXECUTION_FAILURE;
			args++;
			continue ;
		}
		delete_env_lst(data, ft_strndup(*args, ft_getcharindex(*args, '=')));
		args++;
	}
	data->env_size = ft_envlst_size(data->env_lst);
	update_env_arr(data);
	if (data->exit_status != EXECUTION_FAILURE)
		data->exit_status = EXECUTION_SUCCESS;
}
