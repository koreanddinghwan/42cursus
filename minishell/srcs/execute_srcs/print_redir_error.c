/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_redir_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:05:16 by myukang           #+#    #+#             */
/*   Updated: 2022/06/30 10:24:40 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

void	set_original_path(char *path, char **original_path)
{
	if (ft_strncmp(path, "./", 2) == 0)
		*original_path = ft_strdup(path + 2);
	else
		*original_path = ft_strdup(path);
}

int	print_redir_error(char *path, char *error_str)
{
	char	*original_path;

	original_path = NULL;
	set_original_path(path, &original_path);
	write(2, "mgyush > ", 9);
	write(2, original_path, ft_strlen(original_path));
	write(2, ": ", 2);
	ft_putendl_fd(error_str, 2);
	if (original_path)
		free(original_path);
	return (FAIL);
}
