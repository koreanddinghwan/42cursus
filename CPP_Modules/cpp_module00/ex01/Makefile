# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/03 17:22:13 by myukang           #+#    #+#              #
#    Updated: 2022/07/07 14:46:42 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = c++ -Wall -Werror -Wextra -g3
STD = -std=c++98

SRCS = $(addprefix ./, PhoneBook.cpp Contact.cpp main.cpp)
OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(STD) $^ -o $@

%.o : %.c
	$(CC) $(STD) $^ -c

clean :
	rm -rf $(OBJS)

fclean :
	make clean;
	rm -rf $(NAME);

re :
	make fclean;
	make all;

.PHONY : all clean fclean re
