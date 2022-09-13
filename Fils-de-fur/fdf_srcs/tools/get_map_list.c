/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 04:37:56 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 21:02:12 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_map_list(char	*path, t_dlst **line_list)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Please check map path");
		exit(1);
	}
	line = get_next_line(fd);
	while (line)
	{
		ft_dlst_pushback(line_list, ft_dlst_new(line));
		line = get_next_line(fd);
	}
	close(fd);
}
