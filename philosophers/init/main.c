/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:30:06 by myukang           #+#    #+#             */
/*   Updated: 2022/05/30 15:25:17 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	*data;

	if (init_data(&data, ac, av) == FAIL)
		return (1);
	if (init_thread(data) == FAIL)
		return (1);
	if (join_thread(data) == FAIL)
		return (1);
	if (av[5])
		print_total_eat(data);
//	all_free(data);
	return (0);
}
