/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 14:26:48 by myukang           #+#    #+#             */
/*   Updated: 2022/06/03 08:36:48 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
 * when philo routine start, let the last_eat_time t_now
 * if action function return FAIL, routine is break and 
 * free parameter and finished
 *
 * */

#include "philo.h"

void	*philo(void *param)
{
	t_param		*p;

	p = (t_param *)param;

	pthread_mutex_lock(p->data->status);
	p->phdata->last_eat = p->data->init_time;
	p->phdata->ph_init_time = p->data->init_time;
	pthread_mutex_unlock(p->data->status);
	while (1)
	{
		if (eating(p->data, p->phdata) == FAIL)
			break ;
		if (sleeping(p->data, p->phdata) == FAIL)
			break ;
		if (thinking(p->data, p->phdata) == FAIL)
			break ;
	}
	free(param);
	return (0);
}
