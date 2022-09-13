/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_replaced.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 03:52:22 by myukang           #+#    #+#             */
/*   Updated: 2022/06/20 12:49:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.h"

void	cpy_exitstatus(char **rtn, char **str, t_data *data)
{
	char	*exit;
	char	*rtn_cur;
	int		exit_len;
	int		i;

	exit = ft_itoa(data->exit_status);
	rtn_cur = *rtn;
	i = 0;
	while (exit[i])
	{
		rtn_cur[i] = exit[i];
		i++;
	}
	exit_len = ft_strlen(exit);
	while (exit_len)
	{
		*rtn += 1;
		exit_len--;
	}
	*str += 2;
	free(exit);
}

void	cpy_env(char **rtn, char *value)
{
	char	*rtn_cur;
	int		value_len;
	int		i;

	rtn_cur = *rtn;
	i = 0;
	while (value[i])
	{
		rtn_cur[i] = value[i];
		i++;
	}
	value_len = ft_strlen(value);
	while (value_len)
	{
		value_len--;
		*rtn += 1;
	}
}

void	check_env(char **rtn, char **str, t_envlst *envlst)
{
	char	*cp;
	char	*cur;
	int		cplen;

	cur = *str;
	cp = make_possible_cp(cur + 1);
	while (envlst)
	{
		if (ft_strcmp(envlst->key, cp) == 0)
		{
			cpy_env(rtn, envlst->value);
			break ;
		}
		envlst = envlst->next;
	}
	cplen = ft_strlen(cp) + 1;
	while (cplen)
	{
		(*str) += 1;
		cplen--;
	}
	free(cp);
}

void	cpy_replaced(char *rtn, char *str, t_data *data, int len)
{
	if (len != 0)
	{
		while (*str)
		{
			if (*str == '$' && *(str + 1) == '?')
				cpy_exitstatus(&rtn, &str, data);
			else if (*str == '$' && *(str + 1) != '\0' && *(str + 1) != '$')
				check_env(&rtn, &str, data->env_lst);
			else
			{
				*rtn = *str;
				rtn++;
				str++;
			}
		}
	}
	*rtn = '\0';
}
