/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyumpark <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 12:31:24 by gyumpark          #+#    #+#             */
/*   Updated: 2022/06/30 13:40:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	ft_env(t_data *data, char **args)
{
	t_envlst	*lst;
	int			ac;

	lst = data->env_lst;
	ac = get_argv_count(args);
	if (ac == 1)
	{
		while (lst)
		{
			printf("%s=%s\n", (char *)lst->key, (char *)lst->value);
			lst = lst->next;
		}
	}
	else
		exit(EX_NOTFOUND);
}
