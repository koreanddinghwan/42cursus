/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fs_bitmasking.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:21:19 by myukang           #+#    #+#             */
/*   Updated: 2022/06/28 01:28:54 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FS_BITMASKING_H
# define FS_BITMASKING_H

int	exist_slash(char *cmd);
int	isdir(int st_mode);
int	isreg(int st_mode);
int	isexec(int st_mode);

# define FS_IFMT		0170000
# define FS_IFDIR		0040000
# define FS_IFREG		0100000
# define FS_IXUSR		00100
#endif
