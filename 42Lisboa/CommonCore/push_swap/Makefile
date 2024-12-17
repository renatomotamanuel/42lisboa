# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scorpot <scorpot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 16:07:13 by scorpot           #+#    #+#              #
#    Updated: 2024/12/17 20:59:44 by scorpot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS =	ft_printf.c ft_printf_utils.c main.c ft_split.c
		
OBJS = $(SRCS:.c=.o)

.c.o:
	sudo $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	sudo $(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	sudo rm -f $(OBJS)

fclean: clean
	sudo rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re