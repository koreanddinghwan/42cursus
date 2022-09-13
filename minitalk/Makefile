# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/09 15:53:38 by myukang           #+#    #+#              #
#    Updated: 2022/05/12 13:10:16 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER = server
CLIENT = client
GCC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = ./libft.a
INC = ./includes/
DIR = ./minitalk_srcs/

CLIENT_SRCS = client.c
CLIENT_OBJS_O = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(DIR), $(CLIENT_OBJS_O))

SERVER_SRCS = server.c 
SERVER_OBJS_O = $(SERVER_SRCS:.c=.o)
SERVER_OBJS = $(addprefix $(DIR), $(SERVER_OBJS_O))

BONUS_DIR = ./bonus_srcs/

BONUS_SERVER = server_bonus
BONUS_SERVER_SRCS = server_bonus.c 
BONUS_SERVER_OBJS_O = $(BONUS_SERVER_SRCS:.c=.o)
BONUS_SERVER_OBJS = $(addprefix $(BONUS_DIR), $(BONUS_SERVER_OBJS_O))

BONUS_CLIENT = client_bonus
BONUS_CLIENT_SRCS = client_bonus.c client_err_check_bonus.c  
BONUS_CLIENT_OBJS_O = $(BONUS_CLIENT_SRCS:.c=.o)
BONUS_CLIENT_OBJS = $(addprefix $(BONUS_DIR), $(BONUS_CLIENT_OBJS_O))

OBJS_FOR_CLEAN =  $(CLIENT_OBJS) $(SERVER_OBJS) $(BONUS_SERVER_OBJS) $(BONUS_CLIENT_OBJS)


all : $(LIBFT) $(SERVER) $(CLIENT)

$(NAME) : all

$(LIBFT) : 
	@make -C ./libft/
	@mv ./libft/$(LIBFT) ./$(LIBFT)

$(SERVER) : $(SERVER_OBJS)
	@$(GCC) $(CFLAGS) -o $@ $^ -I$(INC) $(LIBFT)

$(CLIENT) : $(CLIENT_OBJS)
	@$(GCC) $(CFLAGS) -o $@ $^ -I$(INC) $(LIBFT)

bonus : $(LIBFT) $(BONUS_CLIENT) $(BONUS_SERVER)

$(BONUS_CLIENT)  : $(BONUS_CLIENT_OBJS)
	@$(GCC) $(CFLAGS) -o $@ $^ -I$(INC) $(LIBFT)

$(BONUS_SERVER) : $(BONUS_SERVER_OBJS)
	@$(GCC) $(CFLAGS) -o $@ $^ -I$(INC) $(LIBFT)

%.o :  %.c
	@$(GCC) $(CFLAGS) -c -o $@ $^ -I$(INC)

clean : 
	make clean -C ./libft
	rm -rf $(LIBFT) $(OBJS_FOR_CLEAN)

fclean : 
	make clean
	rm -rf $(NAME) $(SERVER) $(CLIENT) $(BONUS_SERVER) $(BONUS_CLIENT)

re : 
	make fclean
	make all
	
.PHONY : all clean fclean re
