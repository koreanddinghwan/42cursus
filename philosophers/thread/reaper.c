/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 20:54:54 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:52:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * reaper routine
 * if philo is only one, exec checking_a
 * in this section a thread is waiting for mutex lock (left fork)
 * so, 
 * t_usleep for time_to_die
 * write data->isdead to DEAD
 * and unlock left fork
 *
 * in checking c, only check the differences between 
 * currtime and last_eat_time over time_to_die.
 *
 * checking b, check both upper and is every philosophers eat times_must_eat
 *
 * usleep 100 is for write mutex 
 * because too many write mutex use in reaper routine,
 * will cause interrupting philo thread use of write mutex 
 * */

#include "philo.h"

void	*checking_dead(t_data *data)
{
	int		i;

	i = 0;
	while (1)
	{
		usleep(500);
		if (check_dead(data, data->phdata + i) == DEAD)
			return (0);
		i++;
		if (i == data->num)
			i = 0;
	}
	return (0);
}

void	*checking_dead_meal(t_data *data)
{
	int		i;

	i = 0;
	while (1)
	{
		usleep(500);
		if (check_dead(data, data->phdata + i) == DEAD)
			return (0);
		usleep(500);
		if (check_meal(data) == OVER)
			return (0);
		i++;
		if (i == data->num)
			i = 0;
	}
	return (0);
}

void	*reaper(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->times_must_eat >= 0)
		return (checking_dead_meal(data));
	else
		return (checking_dead(data));
}
