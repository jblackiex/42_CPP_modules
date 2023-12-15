NAME = PmergeMe

SRC = main.cpp PmergeMe.cpp
OBJS = $(SRC:.cpp=.o)

CC = c++
RM = rm -f
FLAGS = -g -Wall -Werror -Wextra -std=c++98 #-Wshadow

###### COLORS ########

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "make all"
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	@echo "$(RED)rm -f $(NAME)$(DEF_COLOR)"

re: fclean all

.PHONY: all clean fclean re
