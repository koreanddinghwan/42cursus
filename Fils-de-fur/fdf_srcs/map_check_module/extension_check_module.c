/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extension_check_module.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 20:55:30 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 20:56:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	validate_file_extension(char *path)
{
	char	**splited;
	int		i;

	splited = ft_split(path, '.');
	i = 0;
	while (splited[i])
		i++;
	i--;
	if (ft_strncmp("fdf", splited[i], ft_strlen(splited[i])))
	{
		free_split(splited);
		return (0);
	}
	free_split(splited);
	return (1);
}

int	extension_check_module(char *path)
{
	if (!validate_file_extension(path))
		call_error(
			"that map file is not a fdf map\nplease insert valid map file\n");
	return (1);
}
