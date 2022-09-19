/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_think.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:37:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/30 14:04:45 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * sleeping and thinking action.
 * each action print will prevent from 
 * after a philo is dead by write_msg function
 *
 * in sleeping function t_usleep,
 * the time to sleep is time_to_sleep + time_to_eat
 * because last_eat time is set eating-write-time 
 * so sleeping time should be from last_eat time 
 * to time_to_sleep + time_to_eat
 * */

#include "philo.h"

int	sleeping(t_data *data, t_phdata *phdata)
{
	if (write_msg(data, t_diff(phdata->ph_init_time), phdata, SLEEP) == FAIL)
		return (FAIL);
	t_usleep(phdata->last_eat, data->time_to_sleep + data->time_to_eat);
	return (SUCCESS);
}

int	thinking(t_data *data, t_phdata *phdata)
{
	if (write_msg(data, t_diff(phdata->ph_init_time), phdata, THINK) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
