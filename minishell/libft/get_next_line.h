/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:38:55 by myukang           #+#    #+#             */
/*   Updated: 2022/06/27 17:09:47 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft.h"
# define OPEN_MAX 256
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*ft_readline(int fd, char *save);
char	*ft_get_rtn(char *line);
char	*ft_get_newsave(char *save);
char	*ft_gnljoin(char *save, char *buffer, int *rd_rtn);
char	*ft_gnlchr(const char *s, int c);

#endif
