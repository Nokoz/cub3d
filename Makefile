NAME = cub3D

SRC_DIR = ./ray

OBJ_DIR = .objs

SRCS = main.c \
	   ./ray/ray.c \
	   ./ray/move.c \
	   ./ray/start_cast.c \
	   ./ray/rotation_collision.c \
	   ./ray/mlx_image_wrapper.c \
	   ./ray/walls.c \
	   ./ray/free_ray.c \
	   ./ray/mini_map.c \
	   ./PARSING/parsing_map.c \
	   ./PARSING/init.c \
	   ./PARSING/convert.c \
	   ./PARSING/parsing_arg.c \
	   ./PARSING/handle_mlx.c \
	   ./PARSING/ft_split.c \
	   ./PARSING/path_finding.c \
	   ./PARSING/init_utils.c \
	   ./PARSING/utils.c \
	   ./PARSING/free.c \
	   ./PARSING/utils_2.c \
	   ./PARSING/texture_on_map.c \
	   ./PARSING/convert_rgb.c \
	   ./GET_NEXT_LINE/get_next_line.c \
	   ./GET_NEXT_LINE/get_next_line_utils.c

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC = gcc
HEAD = -lmlx -framework OpenGL -framework Appkit
CFLAGS =  -IINCS -Wall -Werror -Wextra
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(CFLAGS) -o $(NAME) $(HEAD)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $(<F)"

clean:
		@$(RM) $(OBJ_DIR)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
		@$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
