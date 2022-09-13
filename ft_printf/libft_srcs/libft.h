/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.kr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:21:11 by myukang           #+#    #+#             */
/*   Updated: 2022/03/29 01:51:22 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define  LIBFT_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef unsigned long	t_size_t;

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
t_size_t		ft_strlen(char *s);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memset(void *b, int c, t_size_t len);
void			ft_bzero(void *s, t_size_t n);
void			*ft_memcpy(void *dst, const void *src, t_size_t n);
void			*ft_memmove(void *dst, const void *src, t_size_t len);
void			*ft_memchr(const void *s, int c, t_size_t n);
int				ft_memcmp(const void *s1, const void *s2, t_size_t n);
t_size_t		ft_strlcat(char *dest, char *src, t_size_t size);
t_size_t		ft_strlcpy(char *dest, char *src, t_size_t size);
int				ft_strncmp(char *s1, char *s2, t_size_t n);
char			*ft_strdup(char *src);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
					const char *needle, t_size_t len);
void			*ft_calloc(t_size_t count, t_size_t size);
char			*ft_substr(char const *s, unsigned int start, t_size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putendl_fd(char *s, int fd);
t_list			*ft_lstnew(void	*content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void*));
t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));
int				ft_putnbr_unsigned(unsigned int n, int fd);
#endif
