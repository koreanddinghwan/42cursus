/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myukang <myukang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:21:11 by myukang           #+#    #+#             */
/*   Updated: 2022/05/01 03:06:37 by myukang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define  LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_dlst
{
	void			*content;
	struct s_dlst	*next;
	struct s_dlst	*back;
}	t_dlst;

# ifndef T_SIZE
#  define T_SIZE

typedef unsigned long	t_size;
# endif

int				ft_isspace(char c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
t_size			ft_strlen(char *s);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memset(void *b, int c, t_size len);
void			ft_bzero(void *s, t_size n);
void			*ft_memcpy(void *dst, const void *src, t_size n);
void			*ft_memmove(void *dst, const void *src, t_size len);
void			*ft_memchr(const void *s, int c, t_size n);
int				ft_memcmp(const void *s1, const void *s2, t_size n);
t_size			ft_strlcat(char *dest, char *src, t_size size);
t_size			ft_strlcpy(char *dest, char *src, t_size size);
int				ft_strncmp(char *s1, char *s2, t_size n);
char			*ft_strdup(char *src);
int				ft_atoi(const char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *haystack,
					const char *needle, t_size len);
void			*ft_calloc(t_size count, t_size size);
char			*ft_substr(char const *s, unsigned int start, t_size len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			**ft_split_charset(char *str, char *charset);
void			ft_freesplit(char ***s, int *p_index);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
int				ft_putchar_fd(char c, int fd);
int				ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
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
int				ft_printf(const char *fmt, ...);
int				ft_putnbr_unsigned(unsigned int n, int fd);
int				ft_putnbr_hex(int n, int big_small);
int				ft_print_pointer(void *p);
t_dlst			*ft_dlst_new(void *content);
t_dlst			*ft_dlst_last(t_dlst *dlst);
void			ft_dlst_delone(t_dlst *dlst, void (*del)(void *));
void			ft_dlst_clear(t_dlst **dlst, void (*del)(void *));
int				ft_dlst_size(t_dlst *lst);
t_dlst			*ft_dlst_popback(t_dlst **dlst);
t_dlst			*ft_dlst_popfront(t_dlst **dlst);
void			ft_dlst_pushback(t_dlst **dlst, t_dlst *new);
void			ft_dlst_pushfront(t_dlst **dlst, t_dlst *new);
#endif
