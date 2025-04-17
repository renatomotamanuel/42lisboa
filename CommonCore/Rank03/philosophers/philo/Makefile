# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmota-ma <rmota-ma@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/31 14:22:21 by rmota-ma          #+#    #+#              #
#    Updated: 2025/04/04 15:19:01 by rmota-ma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -g -Wall -Werror -Wextra

SRC_DIR = srcs
OBJ_DIR = objs

SRC_FILES = main.c lib_inc.c philo.c actions.c

SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(SRC_OBJ)
	@echo "\033[33mCompiling Philosophers..."
	@$(CC) $(CFLAGS) $(SRC_OBJ) -o $(NAME)
	@echo "\033[33mPhilosophers Compiled!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "\033[33mCleaning..."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BNS_OBJ_DIR)
	@echo "\033[33mClean!"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(BNS_NAME)

re: fclean all

.PHONY: all clean fclean re