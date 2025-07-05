NAME       := cub3D
CC         := cc
CFLAGS     := -Wall -Wextra -Werror -g3

SRC_DIR    := src
OBJ_DIR    := objects
LIBFT_DIR  := libft
MLX_DIR    := minilibx
INCLUDE    := -I includes -I $(LIBFT_DIR) -I $(MLX_DIR)

SRC_FILES  := \
	main.c \
	utils/exit.c \
	utils/free.c \
	utils/error.c \
	init/init_data.c \
	init/init_mlx.c \
	init/init_textures.c \
	parsing/create_map.c \
	parsing/fill_dir_tex.c \
	parsing/parse_file.c \
	parsing/validate_arg.c \
	parsing/fill_col_tex.c \
	parsing/get_file_data.c \
	parsing/utils.c \
	print_all.c

SRCS       := $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS       := $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIBFT_LIB  := $(LIBFT_DIR)/libft.a
MLX_LIB    := $(MLX_DIR)/libmlx.a

LDLIBS     := $(LIBFT_LIB) $(MLX_LIB) -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $@ $(LDLIBS)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
