/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:49:10 by myukang           #+#    #+#             */
/*   Updated: 2022/05/28 15:56:46 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_memory(t_data *data)
{
	data->phdata = malloc(sizeof(t_phdata) * data->num);
	if (!data->phdata)
		return (FAIL);
	data->t_arr = malloc(sizeof(pthread_t) * data->num);
	if (!data->t_arr)
		return (FAIL);
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num);
	if (!data->forks)
		return (FAIL);
	data->write = malloc(sizeof(pthread_mutex_t));
	data->status = malloc(sizeof(pthread_mutex_t));
	return (SUCCESS);
}

int	init_data_mem(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	if (!*data)
		return (FAIL);
	return (SUCCESS);
}
