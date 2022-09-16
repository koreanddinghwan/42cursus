# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 19:13:04 by myukang           #+#    #+#              #
#    Updated: 2022/07/14 17:52:05 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = simulation
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -g3 -std=c++98
INC = .

SRCS = $(addprefix ./, main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INC) $^ -o $@

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -I$(INC) -c $^ -o $@

clean :
	rm -rf $(OBJS)

fclean :
	make clean;
	rm -rf $(NAME);

re :
	make fclean;
	make all;

.PHONY : all clean fclean re
