/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/12 13:19:04 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*client. 
 *1. 인자로 받은 pid로 SIGUSR1을 보냄.
 2. 서버는 이걸 받으면 pause가 풀리면서 SIGUSR1을 보냄
 3. 클라이언트는 이 시그널을 받으면 비트를 하나씩 전송함
 4. 서버는 각 비트를 받을때마다 클라이언트에 자신이 받은 비트가 맞는지 확인하고,
         |
 * */

#include "client_bonus.h"

void	request_char(int pid, char c)
{
	int		i;

	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	i = 0;
	while (i < 8)
	{
		if (c & 0x1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(100);
	}
}

void	request_to_server(char **av)
{
	int		pid;
	char	*str;
	int		i;

	pid = ft_atoi(av[1]);
	i = 2;
	kill(pid, SIGUSR1);
	while (av[i])
	{
		str = av[i];
		while (*str)
		{
			request_char(pid, *str);
			str++;
		}
		i++;
		if (av[i])
			request_char(pid, '\n');
	}
}

int	main(int ac, char **av)
{
	int	server_pid;

	client_ac_check(ac);
	server_pid = ft_atoi(av[1]);
	client_spid_check(server_pid);
	request_to_server(av);
	return (0);
}
