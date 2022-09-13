/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_heredoc_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:32:53 by myukang           #+#    #+#             */
/*   Updated: 2022/07/01 18:15:57 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

int	set_heredocnum(t_dlst *iolst)
{
	int	c;

	c = 0;
	while (iolst)
	{
		if (get_io_cont(iolst)->type == W_HERE_DOC)
			c++;
		iolst = iolst->next;
	}
	return (c);
}

void	write_free_strings(t_data *data, char *input, int fd)
{
	char	*replaced;

	replaced = get_replaced(data, input);
	if (!replaced)
	{
		replaced = ft_strdup("");
		free(input);
	}
	write(fd, replaced, ft_strlen(replaced));
	write(fd, "\n", 1);
	free(replaced);
}
