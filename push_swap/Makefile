CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
NAME = push_swap
FT = push_swap.a
INC = /includes/

#LIBFT
LIBFT = libft.a
LIBFT_DIR = ./libft/

#push_swap
PUSH_SWAP_MAIN = ./push_swap_srcs/main.c

BASIC_DIR = ./push_swap_srcs/basic/
BASIC_SRCS_C = init_argv.c init_stack.c init_list.c sort_stack.c
BASIC_OBJS_O = $(BASIC_SRCS_C:.c=.o)
BASIC_OBJS = $(addprefix $(BASIC_DIR), $(BASIC_OBJS_O)) 

INST_DIR = ./push_swap_srcs/instruments/
INST_SRCS_C = push.c reverse_rotate.c rotate.c swap.c
INST_OBJS_O = $(INST_SRCS_C:.c=.o) 
INST_OBJS = $(addprefix $(INST_DIR), $(INST_OBJS_O))

HG_DIR = ./push_swap_srcs/hourglass_sort/
HG_SRCS_C = make_chunk.c chunk_min_max_init.c hourglass_sort.c rotate_after_pushb.c
HG_OBJS_O = $(HG_SRCS_C:.c=.o) 
HG_OBJS = $(addprefix $(HG_DIR), $(HG_OBJS_O))

SORT_DIR = ./push_swap_srcs/sort/
SORT_SRCS_C = descend_sort.c ten_sort.c three_sort.c hundred_sort.c five_hundred_sort.c
SORT_OBJS_O = $(SORT_SRCS_C:.c=.o)
SORT_OBJS = $(addprefix $(SORT_DIR), $(SORT_OBJS_O))

TOOLS_DIR = ./push_swap_srcs/tools/
TOOLS_SRCS_C = call_error.c list_sort_check.c num_avail_check.c quick_sort_list.c get_status.c
TOOLS_OBJS_O = $(TOOLS_SRCS_C:.c=.o)
TOOLS_OBJS = $(addprefix $(TOOLS_DIR), $(TOOLS_OBJS_O))

CLEAR_DIR = ./push_swap_srcs/b_stack_sort/
CLEAR_SRCS_C = b_clear.c sort_top_three.c
CLEAR_OBJS_O = $(CLEAR_SRCS_C:.c=.o)
CLEAR_OBJS = $(addprefix $(CLEAR_DIR), $(CLEAR_OBJS_O))


OBJ_FILES = $(BASIC_OBJS) $(INST_OBJS) $(SORT_OBJS) $(TOOLS_OBJS) $(HG_OBJS) $(CLEAR_OBJS)

all : $(NAME)

$(NAME) : $(FT)

$(FT) : $(OBJ_FILES) $(PUSH_SWAP_MAIN)
	$(MAKE) all -C $(LIBFT_DIR) #MAKE -C, RECURSIVELY MAKE IN ROUTE
	cp $(LIBFT_DIR)$(LIBFT) $(FT)
	ar rcs $(FT) $(OBJ_FILES)
	$(CC) -Wall -Wextra -Werror -o $(NAME) $^ $(FT)

%.o : %.c
	$(CC) $(CFLAGS) $< -o $@ -I$(INC)

fclean : clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) 

clean :
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ_FILES) $(FT)

re : fclean all

.PHONY: all clean fclean re 
