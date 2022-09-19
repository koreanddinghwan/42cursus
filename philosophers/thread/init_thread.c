/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:28:08 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:54:45 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*make_param(t_data *data, int i)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		return (0);
	param->data = data;
	param->phdata = data->phdata + i;
	return ((void *)param);
}

int	init_thread(t_data *data)
{
	int		i;

	i = 0;
	data->init_time = t_now();
	while (i < data->num)
	{
		if (pthread_create(data->t_arr + i, 0, philo, make_param(data, i)) != 0)
			return (FAIL);
		usleep(400);
		i++;
	}
	usleep(100);
	if (pthread_create(&data->t_reaper, 0, reaper, data) != 0)
		return (FAIL);
	return (SUCCESS);
}
