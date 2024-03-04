NAME = cub3d

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = ./src/

OBJ_DIR = .objs/

SRCS = $(shell find ./src -iname "*.c")

OBJ = $(SRCS: .c=.o)
CC = gcc
HEAD = -L $(LIBFT_PATH) -lft
CFLAGS = -Wall -Werror -Wextra #-fsanitize=address
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_PATH)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) -lmlx -framework OpenGL -framework Appkit -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;199mCompiling\033[0m $(<F)"

clean:
		make clean -C $(LIBFT_PATH)
		@$(RM) $(OBJ_DIR)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving objects\033[0m"

fclean: clean
		make fclean -C $(LIBFT_PATH)
		@$(RM) $(NAME)
		@echo "\033[0;32m[OK]\033[0m    \033[0;38;5;44mRemoving $(NAME)\033[0m"

re: fclean all

.PHONY: all clean fclean re
