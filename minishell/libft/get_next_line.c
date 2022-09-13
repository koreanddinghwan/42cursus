/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:38:37 by myukang           #+#    #+#             */
/*   Updated: 2022/06/26 14:00:59 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

char	*ft_get_newsave(char *save)
{
	char	*newsave;
	int		save_i;
	int		newsave_i;

	save_i = 0;
	newsave_i = 0;
	while (save[save_i] && (save[save_i] != '\n'))
		save_i++;
	if (save[save_i] == 0)
	{
		free(save);
		return (0);
	}
	newsave = ft_calloc(ft_strlen(save) - save_i + 1, sizeof(char));
	if (!newsave)
		return (0);
	save_i++;
	while (save[save_i])
		newsave[newsave_i++] = save[save_i++];
	newsave[newsave_i] = '\0';
	free(save);
	return (newsave);
}

char	*ft_get_rtn(char *line)
{
	int		i;
	char	*rtn;

	i = 0;
	if (line[0] == 0)
		return (0);
	while (line[i] && (line[i] != '\n'))
		i++;
	rtn = ft_calloc((i + 1 + (line[i] == '\n')), sizeof(char));
	if (!rtn)
		return (0);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		rtn[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		rtn[i] = line[i];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}

char	*ft_readline(int fd, char *save)
{
	char	*buffer;
	int		rd_rtn;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (0);
	rd_rtn = 1;
	while (!ft_gnlchr(save, '\n') && (rd_rtn > 0))
	{
		rd_rtn = read(fd, buffer, BUFFER_SIZE);
		if (rd_rtn == -1)
		{
			free(buffer);
			return (0);
		}
		if (rd_rtn != BUFFER_SIZE)
			buffer[rd_rtn] = 0;
		save = ft_gnljoin(save, buffer, &rd_rtn);
	}
	free(buffer);
	return (save);
}

char	*get_next_line(int fd)
{
	static char		*save[OPEN_MAX];
	char			*rtn;

	if ((fd < 0) || (BUFFER_SIZE < 1)
		|| OPEN_MAX - 1 < fd || read(fd, 0, 0) < 0)
		return (0);
	save[fd] = ft_readline(fd, save[fd]);
	if (!save[fd])
		return (0);
	rtn = ft_get_rtn(save[fd]);
	save[fd] = ft_get_newsave(save[fd]);
	return (rtn);
}
