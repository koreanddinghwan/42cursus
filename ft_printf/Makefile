# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/18 00:43:51 by myukang           #+#    #+#              #
#    Updated: 2022/03/29 01:55:42 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = libftprintf.a
INC = /includes/

#LIBFT
LIBFT = libft.a
LIBFT_DIR = ./libft_srcs/

#PRINTF
SRCS_DIR = ./printf_srcs/
SRCS_C = ft_printf.c ft_putnbr_hex.c ft_print_pointer.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putnbr_unsigned.c
OBJS_O = $(SRCS_C:.c=.o)
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_C)) 
OBJS = $(addprefix $(SRCS_DIR), $(OBJS_O)) 

OBJ_FILES = $(OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(MAKE) all -C $(LIBFT_DIR) #MAKE -C, RECURSIVELY MAKE IN ROUTE
	cp $(LIBFT_DIR)$(LIBFT) $(NAME)
	ar rcs $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS)  $< -o $@ -I$(INC)

fclean : clean
	rm -f $(NAME)

clean :
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ_FILES)

re : fclean all

.PHONY: all clean fclean re 
