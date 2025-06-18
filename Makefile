NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

MLX_PATH	= ./minilibx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

LIBFT_PATH	= ./libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

OBJ_PATH	= ./objects/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

INCLUDE = -I ./includes -I $(LIBFT_PATH) -I $(MLX_PATH)
RM = rm -rf

SRC = ./sources/
SRC_FILES = 
SRCS	= $(addprefix $(SRC), $(SRC_FILES))

all: $(OBJ_PATH) $(MLX) $(LIBFT) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)
	# mkdir -p $(OBJ_PATH)/init
	# mkdir -p $(OBJ_PATH)/parsing
	# mkdir -p $(OBJ_PATH)/movement
	# mkdir -p $(OBJ_PATH)/render
	# mkdir -p $(OBJ_PATH)/debug
	# mkdir -p $(OBJ_PATH)/exit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC) $(LIBFT) $(MLX) -lXext -lX11 -lm

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MLX):
	make -C $(MLX_PATH)

clean:
	$(RM) $(OBJ_PATH)
	make -C $(LIBFT_PATH) clean
	make -C $(MLX_PATH) clean

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
