/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:38:01 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:44:06 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * print_total_eat 
 * will be used in printing each philosopher's eat time
 *
 * get_type_msg
 * will specify msg type and return string literal
 *
 * write_msg
 * 1. this function should check data->isdead == DEAD
 * 		if DEAD, it will return FAIL and philo routine will end
 * 2. if msg type is eat
 * 		we should update last_eat time because of context switching
 *		we have already set this time in grab 2nd fork(the actual time 
 *		that a philosopher should start eating)
 *		but, lock and unlock write mutex takes time because of
 *		mutex lock and also the context switching.
 *		so we should set last_eat = t_now() safely
 * 3. isfull
 * 		this data is used int check_meal function
 * 		in check_meal function, the function will check only this
 * 		data is FULL so we can easly check that philosopher 
 * 		eat least time
 * */
#include "philo.h"

void	print_total_eat(t_data *data)
{
	int			i;
	t_phdata	*phdata;

	if (!data)
		return ;
	i = 0;
	phdata = data->phdata;
	while (i < data->num)
	{
		printf("%d philosopher ate %d times\n",
			(phdata + i)->nth, (phdata + i)->total_eat);
		i++;
	}
}

char	*get_type_msg(int type)
{
	if (type == FORK || type == LFORK)
		return (FORK_MSG);
	else if (type == EAT)
		return (EAT_MSG);
	else if (type == SLEEP)
		return (SLEEP_MSG);
	else if (type == THINK)
		return (THINK_MSG);
	return (0);
}

int	check_data_dead(t_data *data)
{
	pthread_mutex_lock(data->status);
	if (data->isdead == DEAD)
	{
		pthread_mutex_unlock(data->status);
		return (DEAD);
	}
	pthread_mutex_unlock(data->status);
	return (ALIVE);
}

void	change_time_status(t_data *data, t_phdata *phdata, int type)
{
	if (type == LFORK)
	{
		pthread_mutex_lock(data->status);
		phdata->last_eat = t_now();
		pthread_mutex_unlock(data->status);
	}
	if (type == EAT)
	{
		pthread_mutex_lock(data->status);
		phdata->last_eat = t_now();
		phdata->total_eat++;
		pthread_mutex_unlock(data->status);
		if (data->times_must_eat != -1
			&& (phdata->total_eat == data->times_must_eat))
		{
			pthread_mutex_lock(data->status);
			phdata->is_full = FULL;
			pthread_mutex_unlock(data->status);
		}
	}
}

int	write_msg(t_data *data, long long time, t_phdata *phdata, int type)
{
	change_time_status(data, phdata, type);
	if (check_data_dead(data) == DEAD)
		return (FAIL);
	pthread_mutex_lock(data->write);
	if (check_data_dead(data) == DEAD)
	{
		pthread_mutex_unlock(data->write);
		return (FAIL);
	}
	printf("%lld %d %s", time, phdata->nth, get_type_msg(type));
	pthread_mutex_unlock(data->write);
	return (SUCCESS);
}
