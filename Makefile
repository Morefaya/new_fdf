CC = gcc
CFLAG = -Wall -Wextra -Werror
SRC = test.c

#main.c key_event.c draw.c draw_line.c get_pixel.c draw_trandmark.c \
black_screen.c delete_line.c del_trandmark.c tool.c parse.c

SRC_DIR = ./src
SRC_C = $(patsubst %, $(SRC_DIR)/%, $(SRC))
OBJ = $(patsubst %.c, %.o, $(SRC))
OBJ_DIR = ./obj
OBJ_O = $(patsubst %, $(OBJ_DIR)/%, $(OBJ))
HDIR = include
LIB = minilibx_macos/libmlx.a libft/libft.a
L_H = -L minilibx_macos -lmlx -L libft -lft\
-framework Opengl -framework AppKit
FILE = test_maps/42.fdf
NAME = fdf
.PHONY: re run rr clean fclean all

all: $(LIB) $(NAME)

%.a:
	@make -C $(dir $@)

clean_lib:
	@make clean -C minilibx_macos
	@make fclean -C libft

$(NAME): $(OBJ_DIR) $(OBJ_O)
	@$(CC) -o $@ -I $(HDIR) $(L_H) $(OBJ_O) $(CFLAG)
	@echo "\033[32m$(NAME) done\033[0m"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) -c $< -o $@ -I $(HDIR) $(CFLAG)

clean:
	@rm -rf $(OBJ_O)
	@echo "\033[31mobject files removed\033[0m"

fclean: clean clean_lib
	@rm -rf $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "\033[31m$(NAME) removed\033[0m"

re: fclean all

run:
	@./$(NAME) $(FILE) | cat -e

rr: re run
