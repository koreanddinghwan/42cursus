/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_err_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:56:17 by myukang           #+#    #+#             */
/*   Updated: 2022/05/11 17:19:32 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_bonus.h"

void	client_ac_check(int ac)
{
	if (ac < 3)
	{
		ft_printf("argument counts leaks\n");
		exit(1);
	}
}

void	client_spid_check(int server_pid)
{
	if (kill(server_pid, 0))
	{
		ft_printf("unavailable pid\n");
		exit(1);
	}
}

