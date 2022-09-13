/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:43:39 by myukang           #+#    #+#             */
/*   Updated: 2022/07/02 14:17:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	isoption(char *str)
{
	int	status;

	status = TRUE;
	if (*str != '-')
		return (FALSE);
	else
		str++;
	while (*str)
	{
		if (status == FALSE)
			break ;
		if (*str && *str != 'n')
			status = FALSE;
		str++;
	}
	return (status);
}

int	check_option(char **argv)
{
	int	size;

	size = 1;
	argv++;
	while (*argv)
	{
		if (isoption(*argv) == FALSE)
			return (size);
		size++;
		argv++;
	}
	return (size);
}

int	get_argv_count(char **argv)
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

void	print_echo(char **argv, int no_opt_i)
{
	int	i;
	int	option;

	i = 0;
	if (no_opt_i == 1)
		option = FALSE;
	else
		option = TRUE;
	while (argv[no_opt_i])
	{
		write(1, argv[no_opt_i], ft_strlen(argv[no_opt_i]));
		i++;
		no_opt_i++;
		if (argv[no_opt_i])
			write(1, " ", 1);
	}
	if (option == FALSE)
		write(1, "\n", 1);
}

void	ft_echo(t_data *data, char **argv)
{
	int	not_option_index;
	int	argv_count;

	if (!data)
		return ;
	argv_count = get_argv_count(argv);
	if (argv_count == 1)
	{
		write(1, "\n", 1);
		return ;
	}
	not_option_index = check_option(argv);
	print_echo(argv, not_option_index);
	data->exit_status = EXECUTION_SUCCESS;
}
