NAME = blacklist

OBJS =	blacklist.cpp Contact.cpp PhoneBook.cpp

CC = c++
RM = rm -f
FLAGS = -g -Wall -Werror -Wextra -std=c++98

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

all:
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean: fclean

fclean:
	@make
	${RM} ./blacklist
	echo rm -f ./blacklist 

re: fclean all

.PHONY: all clean fclean re
.SILENT:
