/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:49:35 by myukang           #+#    #+#             */
/*   Updated: 2022/05/11 15:10:43 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	request_char(int pid, char c)
{
	int	i;
	int	ret;

	i = 0;
	while (i < 8)
	{
		if (c & 0x1)
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		c = c >> 1;
		i++;
		usleep(100);
	}
}

void	request_to_server(char **av)
{
	int		pid;
	int		ret;
	char	*str;
	int		i;

	pid = ft_atoi(av[1]);
	ret = kill(pid, 0);
	if (ret == -1)
	{
		ft_putstr_fd("Unavailable pid", 2);
		exit(1);
	}
	i = 2;
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
	if (ac < 3)
	{
		ft_putstr_fd("Client Argument should be greater than 2\n", 2);
		exit(1);
	}
	request_to_server(av);
	return (0);
}
