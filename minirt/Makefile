NAME = minirt
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

MINIRT_DIR = ./minirt_srcs/
MINIRT_SRCS = main.c  
MINIRT_OBJS_O = $(MINIRT_SRCS:.c=.o)
MINIRT_OBJS = $(addprefix $(MINIRT_DIR), $(MINIRT_OBJS_O))

TOOLS_DIR = ./minirt_srcs/tools/
TOOLS_SRCS = 
TOOLS_OBJS_O = $(TOOLS_SRCS:.c=.o)
TOOLS_OBJS = $(addprefix $(TOOLS_DIR), $(TOOLS_OBJS_O))

MAP_CHECK_DIR = ./minirt_srcs/map_module/
MAP_CHECK_SRCS = map_open.c 
MAP_CHECK_OBJS_O = $(MAP_CHECK_SRCS:.c=.o)
MAP_CHECK_OBJS = $(addprefix $(MAP_CHECK_DIR), $(MAP_CHECK_OBJS_O))

PIXEL_MOD_DIR = ./minirt_srcs//
PIXEL_MOD_SRCS = 
PIXEL_MOD_OBJS_O = $(PIXEL_MOD_SRCS:.c=.o)
PIXEL_MOD_OBJS = $(addprefix $(PIXEL_MOD_DIR), $(PIXEL_MOD_OBJS_O))

MLX_MOD_DIR = ./minirt_srcs/mlx_module/
MLX_MOD_SRCS = mod_mlx.c open_window.c pixel_print.c bresenham.c 
MLX_MOD_OBJS_O = $(MLX_MOD_SRCS:.c=.o)
MLX_MOD_OBJS = $(addprefix $(MLX_MOD_DIR), $(MLX_MOD_OBJS_O))

OBJ_FILES = $(MINIRT_OBJS) $(GNL_OBJS) $(TOOLS_OBJS) $(MAP_CHECK_OBJS) $(PIXEL_MOD_OBJS) $(MLX_MOD_OBJS)

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

