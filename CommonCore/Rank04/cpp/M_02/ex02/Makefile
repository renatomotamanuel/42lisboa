NAME = Fixed_Points3
CPP = c++
FLAGS = -Wall -Wextra -Werror -g -std=c++98
OBJ_DIR = objs
SRC_DIR = srcs

SRCS = main.cpp Fixed.cpp

OBJ= $(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(NAME): $(OBJ)
	$(CPP) $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CPP) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	
fclean: clean
	@rm -rf $(NAME)
	
re: fclean all

.PHONY: all fclean clean re