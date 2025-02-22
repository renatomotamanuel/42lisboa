# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:07:13 by scorpot           #+#    #+#              #
#    Updated: 2025/02/20 12:56:12 by rmota-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
CFLAGS =  -g -Wall -Werror -Wextra

OBJ_DIR = objs
GNL_DIR = gnl
PF_DIR = ft_printf
SRC_DIR = srcs
MLX_DIR = ./minilibx-linux

PF_FILES = ft_printf.c ft_printf_utils.c
GNL_FILES = get_next_line.c get_next_line_utils.c
SRC_FILES = main.c map_parsing.c map_parsing_2.c map_parsing3.c \
			handle.c draw.c define.c

PF_OBJ = $(addprefix $(OBJ_DIR)/, $(PF_FILES:.c=.o))
GNL_OBJ = $(addprefix $(OBJ_DIR)/, $(GNL_FILES:.c=.o))
SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

MLX = $(MLX_DIR)/libmlx_Linux.a -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(MLX) $(SRC_OBJ) $(PF_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(PF_OBJ) $(GNL_OBJ) $(MLX) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PF_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re