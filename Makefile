NAME = cub3d

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = ./ray

OBJ_DIR = .objs

SRCS = main.c \
	$(shell find ./ray -iname "*.c") \
	$(shell find ./PARSING -iname "*.c") \
	$(shell find ./GET_NEXT_LINE -iname "*.c")

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

CC = gcc
HEAD = -L$(LIBFT_PATH) -lmlx -framework OpenGL -framework Appkit
CFLAGS =  -IINCS -I$(LIBFT_PATH) -Wall -Werror -Wextra #-fsanitize=address
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIBFT_PATH)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) -lft -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) -c $< -o $@
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
