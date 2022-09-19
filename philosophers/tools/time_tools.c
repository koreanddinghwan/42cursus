/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:37:54 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:58:00 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 *t_usleep => more accuracy version of usleep 
 that considering context switching
 when a thread usleep, 
 that thread goes to waiting queue for n microseconds 
 when awake event occur, that thread goes to 
 ready queue and tehn waiting for dispatch 
 in these procedure, usleep(1) is not a actual 1microseconds sleep.
 so that, we can check how long the time passed 
 by calculating difference between t_now and t_obj 
 and we decide we should sleep more or not
 
 usleep(n) 
 n means this thread will be in waiting queue for n microseconds
 and goes to ready queue and dispatched to cpu
 too small n means this routine would be fastly patched and cause 
 interrupt other threads' time to dispatched
 * */
#include "philo.h"

long long	t_now(void)
{
	struct timeval	t;

	gettimeofday(&t, 0);
	return (t.tv_sec * 1000 + t.tv_usec * 0.001);
}

long long	t_diff(long long t)
{
	return (t_now() - t);
}

void	t_usleep(long long t_obj, int sleep_time)
{
	while (t_diff(t_obj) < sleep_time)
		usleep(200);
}
