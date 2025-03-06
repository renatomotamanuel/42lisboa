# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:07:13 by scorpot           #+#    #+#              #
#    Updated: 2025/03/06 15:17:40 by rmota-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BNS_NAME = pipex_bonus
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

PF_DIR = ft_printf
SRC_DIR = srcs
OBJ_DIR = objs
GNL_DIR = gnl

BNS_PF_DIR = ft_printf
BNS_DIR = srcs_bns
BNS_OBJ_DIR = objs_bns
BNS_GNL_DIR = gnl

GNL_FILES = get_next_line.c get_next_line_utils.c
PF_FILES = ft_printf.c ft_printf_utils.c
SRC_FILES = pipex.c ft_split.c lib_inc.c

BNS_GNL_FILES = get_next_line.c get_next_line_utils.c
BNS_PF_FILES = ft_printf.c ft_printf_utils.c
BNS_FILES = pipex_bns.c ft_split.c lib_inc.c lib_inc_2.c doc_handle.c pipe_handle.c

PF_OBJ = $(addprefix $(OBJ_DIR)/, $(PF_FILES:.c=.o))
GNL_OBJ = $(addprefix $(OBJ_DIR)/, $(GNL_FILES:.c=.o))
SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

BNS_PF_OBJ = $(addprefix $(BNS_OBJ_DIR)/, $(PF_FILES:.c=.o))
BNS_GNL_OBJ = $(addprefix $(BNS_OBJ_DIR)/, $(GNL_FILES:.c=.o))
BNS_OBJ = $(addprefix $(BNS_OBJ_DIR)/, $(BNS_FILES:.c=.o))

all: $(NAME)

$(NAME): $(SRC_OBJ) $(PF_OBJ) $(GNL_OBJ)
	@echo "\033[33mCompiling pipex..."
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(PF_OBJ) $(GNL_OBJ) -o $(NAME)
	@echo "\033[33mPipex Compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(PF_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/$(GNL_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

bonus: $(BNS_NAME)

$(BNS_NAME): $(BNS_OBJ) $(BNS_PF_OBJ) $(BNS_GNL_OBJ)
	@$(CC) $(CFLAGS) $(BNS_OBJ) $(BNS_PF_OBJ) $(BNS_GNL_OBJ) -o $(BNS_NAME)

$(BNS_OBJ_DIR)/%.o: $(BNS_DIR)/%.c | $(BNS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BNS_OBJ_DIR)/%.o: $(BNS_DIR)/$(BNS_PF_DIR)/%.c | $(BNS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BNS_OBJ_DIR)/%.o: $(BNS_DIR)/$(BNS_GNL_DIR)/%.c | $(BNS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BNS_OBJ_DIR):
	@mkdir -p $(BNS_OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BNS_OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re