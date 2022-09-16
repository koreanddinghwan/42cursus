# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 14:46:17 by myukang           #+#    #+#              #
#    Updated: 2022/07/08 00:33:04 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=world_war_z
CCP = c++ -Wall -Werror -Wextra -g3
STD = -std=c++98

SRCS = $(addprefix ./, main.cpp Zombie.cpp zombieHorde.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CCP) $(STD) $^ -o $@

%.o : %.cpp
	$(CCP) $(STD) $^ -c

clean :
	rm -rf $(OBJS)

fclean :
	make clean;
	rm -rf $(NAME);

re :
	make fclean;
	make all;

.PHONY : all clean fclean re
