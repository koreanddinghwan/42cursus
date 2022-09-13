/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 19:38:55 by myukang           #+#    #+#             */
/*   Updated: 2022/03/28 12:18:20 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>

# define OPEN_MAX 256
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef unsigned long	t_size_t;
char		*get_next_line(int fd);
char		*ft_readline(int fd, char *save);
char		*ft_get_rtn(char *line);
char		*ft_get_newsave(char *save);
void		*ft_calloc(t_size_t count, t_size_t size);
t_size_t	ft_strlcpy(char *dest, char *src, t_size_t size);
char		*ft_strjoin(char *save, char *buffer, int *rd_rtn);
char		*ft_strndup(char *src, t_size_t n);
char		*ft_strchr(const char *s, int c);
t_size_t	ft_strlen(char *str);

#endif
