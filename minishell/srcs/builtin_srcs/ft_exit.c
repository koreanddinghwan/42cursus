/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:27:07 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 14:32:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_ac(char **argv)
{
	int	c;

	c = 0;
	while (*argv)
	{
		c++;
		argv++;
	}
	return (c);
}

int	exist_alpha(char **argv)
{
	char	*str;

	argv++;
	while (*argv)
	{
		str = *argv;
		while (*str)
		{
			if (ft_isalpha(*str))
				return (TRUE);
			str++;
		}
		argv++;
	}
	return (FALSE);
}

char	*find_first_nonnum(char **argv)
{
	char	*str;

	argv++;
	while (*argv)
	{
		str = *argv;
		while (*str)
		{
			if (ft_isalpha(*str))
				return (*argv);
			str++;
		}
		argv++;
	}
	return (NULL);
}

void	ft_exit(t_data *data, char **argv)
{
	int	ac;

	if (!data)
		return ;
	ac = get_ac(argv);
	if (ac == 1)
	{
		printf("exit\n");
		exit(0);
	}
	else if (exist_alpha(argv) == TRUE)
	{
		ft_putstr_fd("mgyush: exit: ", 2);
		ft_putstr_fd(find_first_nonnum(argv), 2);
		ft_putendl_fd(": numeric argument required", 2);
		exit(255);
	}
	else if (ac == 2)
	{
		printf("exit\n");
		exit(ft_atoi(argv[1]));
	}
	else
		ft_putendl_fd("mgyush: exit: too many arguments", 2);
}
