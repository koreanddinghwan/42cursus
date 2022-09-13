# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: myukang <myukang@student.42.kr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 18:01:47 by myukang           #+#    #+#              #
#    Updated: 2022/05/03 21:10:15 by myukang          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
DEBUG = -g -fsanitize=address
CFLAGS = -Wall -Wextra -Werror -c 
GFLAGS = -I. -framework Metal -framework Metalkit
GCC = gcc
INC = ./includes/

LIBFT_DIR = ./libft/
LIBFT = libft.a
MLX_DIR = ./mlx/
MLX = libmlx.dylib

GNL_DIR = ./gnl/
GNL_SRCS = get_next_line.c get_next_line_utils.c
GNL_OBJS_O = $(GNL_SRCS:.c=.o)
GNL_OBJS = $(addprefix $(GNL_DIR), $(GNL_OBJS_O))

FDF_DIR = ./fdf_srcs/
FDF_SRCS = main.c fils_de_fer.c 
FDF_OBJS_O = $(FDF_SRCS:.c=.o)
FDF_OBJS = $(addprefix $(FDF_DIR), $(FDF_OBJS_O))

TOOLS_DIR = ./fdf_srcs/tools/
TOOLS_SRCS = call_error.c free_split.c get_map_list.c
TOOLS_OBJS_O = $(TOOLS_SRCS:.c=.o)
TOOLS_OBJS = $(addprefix $(TOOLS_DIR), $(TOOLS_OBJS_O))

MAP_CHECK_DIR = ./fdf_srcs/map_check_module/
MAP_CHECK_SRCS = extension_check_module.c 
MAP_CHECK_OBJS_O = $(MAP_CHECK_SRCS:.c=.o)
MAP_CHECK_OBJS = $(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_OBJS_O))

PIXEL_MOD_DIR = ./fdf_srcs/pixel_module/
PIXEL_MOD_SRCS = pixel_init.c pixel_color_parser.c pixel_correction.c pixel_optimization.c
PIXEL_MOD_OBJS_O = $(PIXEL_MOD_SRCS:.c=.o)
PIXEL_MOD_OBJS = $(addprefix $(PIXEL_MOD_DIR), $(PIXEL_MOD_OBJS_O))

MLX_MOD_DIR = ./fdf_srcs/mlx_module/
MLX_MOD_SRCS = mod_mlx.c open_window.c pixel_print.c bresenham.c 
MLX_MOD_OBJS_O = $(MLX_MOD_SRCS:.c=.o)
MLX_MOD_OBJS = $(addprefix $(MLX_MOD_DIR), $(MLX_MOD_OBJS_O))

OBJ_FILES = $(FDF_OBJS) $(GNL_OBJS) $(TOOLS_OBJS) $(MAP_CHECK_OBJS) $(PIXEL_MOD_OBJS) $(MLX_MOD_OBJS)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make all -C $(LIBFT_DIR)
	make all -C $(MLX_DIR)
	mv $(LIBFT_DIR)$(LIBFT) $(LIBFT)
	mv $(MLX_DIR)$(MLX) $(MLX)
	$(GCC) -Wall -Wextra -Werror -o $@ $^ $(MLX) $(LIBFT) $(GFLAGS)

%.o : %.c
	$(GCC) $(CFLAGS) -I$(INC) $< -o $@

fclean : clean
	rm -f $(NAME)

clean :
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJ_FILES) $(LIBFT) $(MLX)

re : fclean all

.PHONY: all clean fclean re 


