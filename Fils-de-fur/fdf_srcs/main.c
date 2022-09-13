/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:50:11 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 20:55:13 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		call_error("please insert map name\n./fdf [mapfile.fdf]\n");
	else if (ac == 2)
	{
		extension_check_module(av[1]);
		fils_de_fer(av[1]);
	}
	exit(1);
}
