/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_macros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:01:10 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 11:49:17 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wait_macros.h"

int	wexitstatus(int status)
{
	return (status >> 8);
}

int	wifstopped(int status)
{
	return ((status & 0177) == 0177);
}

int	wifexited(int status)
{
	return ((status & 0377) == 0);
}

int	wifsignaled(int status)
{
	return (!wifstopped(status) && !wifexited(status));
}

void	change_exitstatus(t_data *data, int status)
{
	if (wifsignaled(status))
		data->exit_status = 128 + ((status) & 0177);
	else if (wexitstatus(status) >= 256)
		data->exit_status = (wexitstatus(status)) % 256;
	else
		data->exit_status = (wexitstatus(status));
}
