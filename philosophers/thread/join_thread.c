/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:33:21 by myukang           #+#    #+#             */
/*   Updated: 2022/05/30 13:08:25 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * detach => if a detached thread end, that thread's resources 
 * will automatically reclaimed
 * join => if a joined thread, main thread will stop until the joined thread end
 *
 * so, philos thread will detached and working independently
 * and reaper thread will joined and 
 * main thread will stop
 * and 
 * if a philo is dead or 
 * all philo are satisfied least_eat, 
 * reaper will write data->status=DEAD and 
 * print end message
 * detached philo threads will get that sign in write_msg function then end,
 * reaper thread end 
 * and main thread will start 
 *
 * we should each thread call detach or join
 * because thread leak occur 
 * "https://developer.apple.com/documentation/xcode/thread-leaks"
 * */
#include "philo.h"

int	join_thread(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		if (pthread_detach(data->t_arr[i]) != 0)
			return (FAIL);
		i++;
	}
	if (pthread_join(data->t_reaper, 0) != 0)
		return (FAIL);
	return (SUCCESS);
}
