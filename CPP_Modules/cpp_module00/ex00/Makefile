# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:22:13 by myukang           #+#    #+#              #
#    Updated: 2022/07/07 01:50:22 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone
CC = c++ -Wall -Werror -Wextra
STD = -std=c++98

SRCS = $(addprefix ./, megaphone.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(STD) $^ -o $@

%.o : %.c
	$(CC) $(STD) $^ -c

clean :
	rm $(OBJS)

fclean :
	make clean;
	rm $(NAME)

re : 
	make fclean;
	make all;

.PHONY : all fclean clean re
