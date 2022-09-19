/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 12:54:47 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:57:36 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * check_dead
 * check differences each phil's last_eat time and current_time
 * if dead, change data->isdead = DEAD and print dying message
 * the changes data->isdead meaning after printing mseeage will
 * ignored by exception handling in write_msg function
 *
 * check_meal
 * int check_meal function, this function will check
 * all philosopher is full
 * if any phil is hungry,
 * this function will return NOTOVER and 
 * checking_dead_meal function's while loop run
 * */

#include "philo.h"

void	dying_message(t_data *data, t_phdata *phdata)
{
	data->isdead = DEAD;
	pthread_mutex_unlock(data->status);
	pthread_mutex_lock(data->write);
	printf("%lld %d %s", t_diff(phdata->ph_init_time), phdata->nth, DIE_MSG);
	pthread_mutex_unlock(data->write);
}

int	check_dead(t_data *data, t_phdata *phdata)
{
	pthread_mutex_lock(data->status);
	if (t_diff(phdata->last_eat) > data->time_to_die)
	{
		dying_message(data, phdata);
		return (DEAD);
	}
	pthread_mutex_unlock(data->status);
	return (ALIVE);
}

int	check_meal(t_data *data)
{
	int	i;

	i = 0;
	pthread_mutex_lock(data->status);
	while (i < data->num)
	{
		if ((data->phdata + i)->is_full == HUNGRY)
		{
			pthread_mutex_unlock(data->status);
			return (NOTOVER);
		}
		i++;
	}
	data->isdead = DEAD;
	pthread_mutex_unlock(data->status);
	return (OVER);
}
