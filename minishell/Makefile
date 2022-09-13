# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 15:11:43 by myukang           #+#    #+#              #
#    Updated: 2022/07/01 15:50:35 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
GCC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 
INC = ./includes

RDINC = ${HOME}/.brew/opt/readline/include #readline include path
RDLIB = ${HOME}/.brew/opt/readline/lib #readline lib path
RDFLAGS = -I${RDINC} -L${RDLIB} -lreadline #readline compile flags

FTDIR = ./libft/
FT = libft.a
FTINC = ./libft/

MAIN_SRCS = $(addprefix ./srcs/main_srcs/, main.c sig_handler.c display.c initialize_main.c initialize_data.c set_envkey.c)
MAIN_OBJS = $(MAIN_SRCS:.c=.o)

TOKEN_SRCS = $(addprefix ./srcs/tokenizer/, tokenizer.c token_buf_build.c)
TOKEN_OBJS = $(TOKEN_SRCS:.c=.o)

LEXER_SRCS = $(addprefix ./srcs/lexer/, lexer.c lexer_token_init.c lexer_decide_w_type.c lexer_word_converter.c lexer_tools.c)
LEXER_OBJS = $(LEXER_SRCS:.c=.o)

PARSE_SRCS = $(addprefix ./srcs/parser/, parser.c parser_tools.c  \
			 make_iolst.c make_cmd.c make_args.c get_cmdtype.c)
PARSE_OBJS = $(PARSE_SRCS:.c=.o)

REPLAC_SRCS = $(addprefix replacer_module/, replacer.c get_replaced_len.c cpy_replaced.c replacer_tool.c)
PATH_SRCS = $(addprefix path_finder_module/, path_finder.c check_envpath.c)
SYNTAX_SRCS = $(addprefix syntax_analyzer_module/, syntax_analyzer.c syntax_error_printer.c pipe_err.c io_err.c)

MODULE_SRCS = $(addprefix ./srcs/module/, $(REPLAC_SRCS) $(SYNTAX_SRCS) $(PATH_SRCS))
MODULE_OBJS = $(MODULE_SRCS:.c=.o)

CLEANER_SRCS = $(addprefix ./srcs/cleaner/, cleaner.c cmd_cont_free.c)
CLEANER_OBJS = $(CLEANER_SRCS:.c=.o)

EXEC_SRCS = $(addprefix ./srcs/execute_srcs/, execute.c set_heredoc.c set_redirection.c set_heredoc_tools.c check_execve_error.c execute_sub.c wait_macros.c print_redir_error.c)
EXEC_OBJS = $(EXEC_SRCS:.c=.o)

BUILTIN_SRCS = $(addprefix ./srcs/builtin_srcs/, ft_cd.c ft_pwd.c ft_exit.c ft_export.c ft_unset.c ft_echo.c ft_env.c export_unset_util.c export_unset_util2.c)
BUILTIN_OBJS = $(BUILTIN_SRCS:.c=.o)

TOOLS_SRCS = $(addprefix ./srcs/tools/, getter1.c getter2.c fs_bitmasking.c)
TOOLS_OBJS = $(TOOLS_SRCS:.c=.o)

OBJ_FILES = $(MAIN_OBJS) $(BUILTIN_OBJS) $(TOOLS_OBJS) $(TOKEN_OBJS) $(LEXER_OBJS) $(MODULE_OBJS) $(PARSE_OBJS) $(CLEANER_OBJS) $(EXEC_OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make all -j 4 -C $(FTDIR) #recursively create libft
	cp $(FTDIR)$(FT) ./$(FT) #copy in root dir
	$(GCC) $(CFLAGS) $(RDFLAGS) -I$(INC) -I$(FTINC) -o $@ $^ libft.a  #RFLAGS for readline lib

%.o : %.c
	$(GCC) $(CFLAGS) -I$(RDINC) -I$(INC) -I$(FTINC) -c $^ -o $@ #specify readline header in RNINC

fclean : clean
	rm -rf $(NAME)

clean :
	make fclean -C $(FTDIR)
	rm -rf $(OBJ_FILES) $(FT)

re : 
	make fclean;
	make all;

.PHONY : all fclean clean re
