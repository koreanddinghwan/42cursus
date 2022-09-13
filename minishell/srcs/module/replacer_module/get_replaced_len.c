/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_replaced_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:59:59 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 21:12:35 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.h"

int	dollar_question_len(char *str, t_data *data)
{
	int		num;
	char	*tmp;

	num = 0;
	while (*str)
	{
		if (*str == '$')
		{
			if (*(str + 1) == '\0')
				break ;
			else if (*(str + 1) == '?')
			{
				num -= 2;
				tmp = ft_itoa(data->exit_status);
				num += ft_strlen(tmp);
				free(tmp);
			}
			else if (*(str + 1) == '$')
				str++;
		}
		if (*str != '\0')
			str++;
	}
	return (num);
}

int	find_env(char *str, t_envlst *env_lst)
{
	char	*cp;
	int		cplen;

	cp = make_possible_cp(str);
	cplen = ft_strlen(cp);
	while (env_lst)
	{
		if (ft_strcmp(env_lst->key, cp) == 0)
		{
			free(cp);
			return ((int)ft_strlen(env_lst->value) - cplen);
		}
		env_lst = env_lst->next;
	}
	free(cp);
	return (0 - cplen);
}

int	env_len(char *str, t_data *data)
{
	t_envlst	*env_lst;
	int			env_num;

	env_lst = data->env_lst;
	env_num = 0;
	while (*str)
	{
		if (*str == '$' && *(str + 1) != 0
			&& *(str + 1) != '?' && *(str + 1) != '$')
			env_num += find_env(str + 1, env_lst) - 1;
		str++;
	}
	return (env_num);
}

int	get_replaced_len(char *str, t_data *data)
{
	int	len;

	len = ft_strlen(str);
	len += dollar_question_len(str, data);
	len += env_len(str, data);
	return (len);
}
