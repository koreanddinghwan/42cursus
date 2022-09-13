/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:43 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/30 14:19:00 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	only_export(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->env[i])
	{
		j = i + 1;
		while (data->env[j])
		{
			if (ft_strcmp(data->env[i], data->env[j]) > 0)
				ft_swap(&data->env[i], &data->env[j]);
			j++;
		}
		i++;
	}
	i = 0;
	while (data->env[i])
	{
		printf("declare -x %s\n", data->env[i]);
		i++;
	}
}

int	export_error(t_data *data, char *str)
{
	if ((!ft_isalpha(*str) && !ft_isunder(*str)))
	{
		ft_putstr_fd("mgyush > export: `", 2);
		ft_putstr_fd(str, 2);
		ft_putendl_fd("\': not a valid identifier", 2);
		data->exit_status = EXECUTION_FAILURE;
		return (FAIL);
	}
	else if (!strchr(str, '='))
		return (FAIL);
	return (SUCESS);
}

int	check_update_env(t_envlst *envlst, char *str)
{
	char	**splited;
	char	*key;

	splited = ft_split(str, '=');
	key = splited[0];
	if (splited[1] == (void *)0)
		splited[1] = ft_strdup("");
	while (envlst)
	{
		if (ft_strcmp(key, (char *)envlst->key) == 0)
		{
			free(envlst->value);
			envlst->value = ft_strdup(splited[1]);
			free(splited[0]);
			free(splited[1]);
			free(splited);
			return (TRUE);
		}
		envlst = envlst->next;
	}
	free(splited[0]);
	free(splited[1]);
	free(splited);
	return (FALSE);
}

void	update_export(t_data *data, char *str)
{
	t_envlst	*envlst;

	envlst = data->env_lst;
	if (check_update_env(envlst, str) == TRUE)
		return ;
	else
		ft_envlst_pushback(&data->env_lst, ft_envlst_new(str));
}

void	ft_export(t_data *data, char **args)
{
	args++;
	if (!*args)
	{
		only_export(data);
		return ;
	}
	while (*args)
	{
		if (export_error(data, *args) == FAIL)
			return ;
		else
			update_export(data, *args);
		args++;
	}
	update_env_arr(data);
	data->exit_status = EXECUTION_SUCCESS;
}
