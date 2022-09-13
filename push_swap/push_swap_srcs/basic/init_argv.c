/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 13:33:02 by myukang           #+#    #+#             */
/*   Updated: 2022/04/24 15:23:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	init_argv(int ac, char ***av)
{
	int		i;
	char	**splited;
	int		split_index;
	int		total_index;

	i = 1;
	total_index = 1;
	while (i < ac)
	{
		splited = ft_split((*av)[i], ' ');
		split_index = 0;
		while (splited[split_index])
		{
			(*av)[total_index] = splited[split_index];
			split_index++;
			total_index++;
		}
		free(splited);
		i++;
	}
	(*av)[total_index] = 0;
	return (total_index);
}
