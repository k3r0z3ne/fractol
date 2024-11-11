# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 17:58:40 by arotondo          #+#    #+#              #
#    Updated: 2024/11/11 16:14:33 by arotondo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include
LIBFT_DIR = libft
PRINTF_DIR = printf
MLX_DIR = minilibx-linux

SRC = main.c draw.c fractals.c error.c utils.c init.c hooks.c
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CFLAGS = -Wall -Wextra -Werror -g3 -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR) -I $(MLX_DIR)
MFLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/bin -lX11 -lXext -lm -lbsd
LIBS = -L $(LIBFT_DIR) -lft -L $(PRINTF_DIR) -lftprintf -L $(MLX_DIR)


DEF_COLOR = \033[0;39m
GREEN = \033[0;92m

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	@make -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME) $(MFLAGS)
	@echo "${GREEN}Compilation of $(NAME) done.${DEF_COLOR}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC_DIR)/fractol.h | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(PRINTF_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}Files clean up done.{DEF_COLOR}"

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@make -C $(PRINTF_DIR) fclean
	@rm -rf $(NAME)
	@echo "${GREEN}Clean up done.{DEF_COLOR}"

re: fclean all

.PHONY: all clean fclean re