/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:50:32 by myukang           #+#    #+#             */
/*   Updated: 2022/05/30 00:06:27 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_mutex_init(data->forks + i, 0) != 0)
			return (FAIL);
		i++;
	}
	if (pthread_mutex_init((data->write), 0) != 0)
		return (FAIL);
	if (pthread_mutex_init((data->status), 0) != 0)
		return (FAIL);
	return (SUCCESS);
}
