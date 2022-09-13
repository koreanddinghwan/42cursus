/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:25 by myukang           #+#    #+#             */
/*   Updated: 2022/05/12 13:20:23 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_server	g_server_set;

static	void	translator(int sig)
{
	int	num;

	num = sig - 30;
	g_server_set.charactor += ft_pow(0x2, g_server_set.total_req_num % 8) * num;
	g_server_set.total_req_num++;
	if (g_server_set.total_req_num % 8 == 0)
	{
		write(1, &g_server_set.charactor, 1);
		g_server_set.charactor = 0;
	}
}

void	handler(int sig)
{
	translator(sig);
}

void	set_connection()
{
	struct sigaction	action;

	
}

int	main(int ac, char **av)
{
	pid_t			pid;

	if (ac > 1)
	{
		ft_putstr_fd("server does not need any arguments\n", 2);
		exit(1);
	}
	else
	{
		pid = getpid();
		ft_printf("%s pid : %d\n", av[0], pid);
		set_connection();
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		while (1)
			pause();
	}
	return (0);
}
