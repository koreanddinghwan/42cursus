/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:10:06 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:33:18 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * release
 * this function will mutex unlock the philosopher's fork mutex
 *
 * grab
 * this function will mutex lock the philosophers's fork mutex
 * each philosopher will grab fork and print
 *
 * after grab two forks,
 * the philo(thread) will sleep time_to_eat
 * and release
 * */

#include "philo.h"

int	release(t_data *data, t_phdata *phdata)
{
	if (phdata->nth == 1)
	{
		pthread_mutex_unlock(data->forks + phdata->left_idx);
		pthread_mutex_unlock(data->forks + phdata->right_idx);
	}
	else
	{
		pthread_mutex_unlock(data->forks + phdata->right_idx);
		pthread_mutex_unlock(data->forks + phdata->left_idx);
	}
	return (SUCCESS);
}

int	grab(t_data *data, t_phdata *phdata)
{
	if (phdata->nth == 1)
	{
		pthread_mutex_lock(data->forks + phdata->left_idx);
		if (write_msg(data, t_diff(phdata->ph_init_time), phdata, FORK) == FAIL)
			return (FAIL);
		pthread_mutex_lock(data->forks + phdata->right_idx);
		if (write_msg(data, t_diff(phdata->ph_init_time),
				phdata, LFORK) == FAIL)
			return (FAIL);
	}
	else
	{
		pthread_mutex_lock(data->forks + phdata->right_idx);
		if (write_msg(data, t_diff(phdata->ph_init_time), phdata, FORK) == FAIL)
			return (FAIL);
		pthread_mutex_lock(data->forks + phdata->left_idx);
		if (write_msg(data, t_diff(phdata->ph_init_time),
				phdata, LFORK) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

int	eating(t_data *data, t_phdata *phdata)
{
	if (grab(data, phdata) == FAIL)
		return (FAIL);
	if (write_msg(data, t_diff(phdata->ph_init_time), phdata, EAT) == FAIL)
		return (FAIL);
	t_usleep(phdata->last_eat, data->time_to_eat);
	return (release(data, phdata));
}
