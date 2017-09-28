# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cweather <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/25 18:45:45 by cweather          #+#    #+#              #
#    Updated: 2017/09/27 21:14:52 by cweather         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CFLAGS = -Wall -Wextra -Werror -g

SRC_FILES = main.c parse_xy.c parse_z.c environment.c \
			slope.c draw.c rotate.c color.c
OBJ_FILES = $(SRC_FILES:.c=.o)

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./includes/
MLX_DIR = ./mlx/
LIBFT_DIR = ./libft/

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
MLX = $(addprefix $(MLX_DIR), libmlx.a)
LIBFT = $(addprefix $(LIBFT_DIR), libft.a)

LINK = -L $(MLX_DIR) -L $(LIBFT_DIR) \
				-lmlx -lft -framework OpenGL -framework AppKit

all: obj $(LIBFT) $(MLX) $(NAME)

obj:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(CFLAGS) -I $(MLX_DIR) -I $(LIBFT_DIR) -I $(INC_DIR) -o $@ -c $<

$(LIBFT):
	@echo "\033[32mCompiling libft..."
	@make -C $(LIBFT_DIR)
	@echo "\033[1;4;32mlibft created.\033[0m"

$(MLX):
	@echo "\033[32mCompiling mlx...\033[0m"
	@make -C $(MLX_DIR)
	@echo "\033[1;4;32mmlx created.\033[0m"

$(NAME): $(OBJ)
	@echo "\033[32mCompiling fdf..."
	@gcc $(OBJ) $(LINK) -lm -o $(NAME)
	@echo "\033[1;4;32m$(NAME) Created.\033[0m"

clean:
	@echo "\033[31mRemoving objects...\033[0m"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@echo "\033[1;4;31Objects removed!\033[0m"

fclean: clean
	@echo "\033[31Removing fdf...\033[0m"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean
	@echo "\033[1;4;31m$(NAME) removed!\033[0m"

re: fclean all

.PHONY: clean fclean all re
