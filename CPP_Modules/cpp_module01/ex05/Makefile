# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:13:04 by myukang           #+#    #+#              #
#    Updated: 2022/07/09 21:58:23 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = simulation
CC = c++
CFLAGS = -Wall -Werror -Wextra -g3 -std=c++98
INC = .

SRCS = $(addprefix ./, main.cpp Harl.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -I$(INC) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean :
	make clean;
	rm -rf $(NAME);

re :
	make fclean;
	make all;

.PHONY : all clean fclean re
