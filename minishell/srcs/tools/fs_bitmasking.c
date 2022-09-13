/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_bitmasking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:16:45 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 16:18:11 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fs_bitmasking.h"

int	isdir(int st_mode)
{
	return ((st_mode & FS_IFMT) == FS_IFDIR);
}

int	isreg(int st_mode)
{
	return ((st_mode & FS_IFMT) == FS_IFREG);
}

int	isexec(int st_mode)
{
	return (isreg(st_mode) && (st_mode & FS_IXUSR));
}
