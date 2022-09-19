/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:03:17 by myukang           #+#    #+#             */
/*   Updated: 2022/05/29 20:56:01 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	validate_struct_num(t_data *data, char **av)
{
	int	i;

	i = 1;
	if (data->num <= 0)
		return (FAIL);
	if (data->time_to_die < 0)
		return (FAIL);
	if (data->time_to_eat < 0)
		return (FAIL);
	if (data->time_to_sleep < 0)
		return (FAIL);
	if (av[5] && data->times_must_eat < 0)
		return (FAIL);
	return (SUCCESS);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	validate_av_num(char **av)
{
	int	i;
	int	err;

	i = 1;
	while (av[i])
	{
		err = check_num(av[i]);
		if (err == FAIL)
			return (FAIL);
		i++;
	}
	return (SUCCESS);
}

int	ac_err(int ac)
{
	if (ac < 5 || ac > 6)
		return (FAIL);
	else
		return (SUCCESS);
}
