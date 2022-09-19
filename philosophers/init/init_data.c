/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:30:46 by myukang           #+#    #+#             */
/*   Updated: 2022/05/30 00:59:05 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	struct_data(t_data *data, char **av)
{
	int	i;

	i = 1;
	data->times_must_eat = -1;
	data->num = ft_atoi(av[i++]);
	data->time_to_die = ft_atoi(av[i++]);
	data->time_to_eat = ft_atoi(av[i++]);
	data->time_to_sleep = ft_atoi(av[i++]);
	if (av[i])
		data->times_must_eat = ft_atoi(av[i]);
	data->isdead = ALIVE;
}

void	init_phdata(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		(data->phdata + i)->nth = i + 1;
		(data->phdata + i)->left_idx = i + 1;
		(data->phdata + i)->right_idx = i;
		(data->phdata + i)->total_eat = 0;
		(data->phdata + i)->is_full = HUNGRY;
		i++;
	}
	(data->phdata + --i)->left_idx = 0;
}

int	init_data(t_data **data, int ac, char **av)
{
	if (ac_err(ac) == FAIL)
		return (FAIL);
	if (validate_av_num(av) == FAIL)
		return (FAIL);
	if (init_data_mem(data) == FAIL)
		return (FAIL);
	struct_data(*data, av);
	if (validate_struct_num(*data, av) == FAIL)
	{
		free(*data);
		return (FAIL);
	}
	if (init_memory(*data) == FAIL)
		return (FAIL);
	if (init_mutex(*data) == FAIL)
		return (FAIL);
	init_phdata(*data);
	return (SUCCESS);
}
