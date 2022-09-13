/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 23:37:30 by myukang           #+#    #+#             */
/*   Updated: 2022/05/03 21:05:10 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# define OPEN_MAX 256
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char		*get_next_line(int fd);
char		*ft_readline(int fd, char *save);
char		*ft_get_rtn(char *line);
char		*ft_get_newsave(char *save);
char		*_ft_strjoin(char *save, char *buffer, int *rd_rtn);
char		*_ft_strndup(char *src, t_size n);

#endif
