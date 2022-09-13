# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/11 17:36:18 by myukang           #+#    #+#              #
#    Updated: 2022/06/30 21:28:18 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
SRCS = ft_isdigit.c ft_isalpha.c ft_isalnum.c ft_isascii.c ft_strlen.c \
	   ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c \
	   ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_strlcat.c \
	   ft_strlcpy.c ft_strncmp.c ft_strdup.c ft_atoi.c ft_strchr.c \
	   ft_strrchr.c ft_strnstr.c ft_calloc.c ft_substr.c ft_strjoin.c \
	   ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	   ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_strcmp.c ft_split_charset.c\
	   ft_printf.c ft_putnbr_hex.c ft_putnbr_unsigned.c ft_print_pointer.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	   ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	   ft_lstiter.c ft_lstmap.c ft_dlst_delone.c ft_dlst_last.c \
	   ft_dlst_clear.c ft_dlst_new.c ft_dlst_popback.c ft_dlst_popfront.c \
	   ft_dlst_pushback.c ft_dlst_pushfront.c ft_dlst_size.c ft_dlst_delete.c\
	   ft_btree_postordertrav.c ft_btree_inordertrav.c ft_btree_preordertrav.c ft_btree_get_right.c ft_btree_get_left.c ft_btree_make_left.c ft_btree_make_right.c ft_btree_new.c \
	   ft_builtin.c get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -c 

OBJ_FILES = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	ar rsc $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I .

fclean : clean
	rm -f $(NAME)

clean :
	rm -f $(OBJS) 

re : fclean all

.PHONY: all clean fclean re 
