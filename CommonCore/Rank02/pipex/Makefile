# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:07:13 by scorpot           #+#    #+#              #
#    Updated: 2025/02/25 20:24:13 by scorpot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS =  -g -Wall -Werror -Wextra

PF_DIR = ft_printf
SRC_DIR = srcs
OBJ_DIR = objs
GNL_DIR = gnl

GNL_FILES = get_next_line.c get_next_line_utils.c
PF_FILES = ft_printf.c ft_printf_utils.c
SRC_FILES = main.c ft_split.c lib_inc.c

PF_OBJ = $(addprefix $(OBJ_DIR)/, $(PF_FILES:.c=.o))
GNL_OBJ = $(addprefix $(OBJ_DIR)/, $(GNL_FILES:.c=.o))
SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))


all: $(NAME)

$(NAME): $(SRC_OBJ) $(PF_OBJ) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(SRC_OBJ) $(PF_OBJ) $(GNL_OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PF_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(GNL_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re