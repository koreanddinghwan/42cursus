# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 16:05:00 by myukang           #+#    #+#              #
#    Updated: 2022/06/03 09:04:28 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
GCC = cc
CFLAGS = -Wextra -Wall -Wextra -pthread 
DEBUG = -g3 -fsanitize=address
INC = ./includes/

ACTION_DIR = ./action/
ACTION_SRCS =  eating.c sleep_think.c checking.c
ACTION_OBJS = $(addprefix $(ACTION_DIR), $(ACTION_SRCS:.c=.o))

INIT_DIR = ./init/
INIT_SRCS = main.c init_data.c init_memory.c init_mutex.c
INIT_OBJS = $(addprefix $(INIT_DIR), $(INIT_SRCS:.c=.o))

THREAD_DIR = ./thread/
THREAD_SRCS = init_thread.c join_thread.c philo.c reaper.c
THREAD_OBJS = $(addprefix $(THREAD_DIR), $(THREAD_SRCS:.c=.o))

TOOLS_DIR = ./tools/
TOOLS_SRCS = argument_validation.c ft_tools.c print_tools.c time_tools.c 
TOOLS_OBJS = $(addprefix $(TOOLS_DIR), $(TOOLS_SRCS:.c=.o))

OBJS = $(ACTION_OBJS) $(INIT_OBJS) $(THREAD_OBJS) $(TOOLS_OBJS)

%.o : %.c
	$(GCC) $(CFLAGS) -g -c $^ -o $@ -I$(INC)

all : $(NAME)
	@echo "Philosophers are ready to eat"

$(NAME) : $(OBJS)
	$(GCC) $(CFLAGS) -g $^ -o $@

debug : $(OBJS)
	$(GCC) $(CFLAGS) $(DEBUG) $^ -o $@

clean :
	rm -rf $(OBJS)

fclean : 
	make clean;
	rm -rf $(NAME) debug

re : 
	make fclean;
	make all;

.PHONY : all clean fclean re
