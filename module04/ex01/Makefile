NAME		= brainedAnimals
SRC_FR		= src/
OBJ_FR		= obj/
INCLUDES	= ./include
CFLAGS		= -Wall -Werror -Wextra -g -I
CC			= c++

# Reset
NC		= \033[0m# 		Text Reset

# Regular Colors
BLACK	= \033[0;30m#	Black
RED		= \033[3;31m#	Red
GREEN	= \033[3;32m#	Green
BLD_GRN	= \033[1;32m#	Green
YELLOW	= \033[3;33m#	Yellow
BLUE	= \033[1;34m#	Blue
PURPLE	= \033[3;35m#	Purple
BLD_PUR	= \033[1;35m#	Purple but bold
CYAN	= \033[3;36m#	Cyan
WHITE	= \033[1;37m#	White

SRC_FILES	:= main.cpp WrongAnimal.cpp WrongCat.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

SRCS		:= $(addprefix $(SRC_FR), $(SRC_FILES))
OBJS		:= $(addprefix $(OBJ_FR), $(SRC_FILES:.cpp=.o))

all: ${NAME}

$(OBJ_FR)%.o : ${SRC_FR}%.cpp | $(OBJ_FR)
	@echo "$(GREEN)compiling:$(NC)" $^
	@${CC} ${CFLAGS} $(INCLUDES) -c $^ -o $@

$(OBJ_FR):
	@echo "$(YELLOW)creating folders...$(NC)"
	@mkdir -p $(OBJ_FR)

$(NAME): ${OBJS}
	@echo "$(GREEN)creating $@...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) $^ -o $@
	@echo "$(BLD_GRN)done!$(NC)"

clean:
	@echo "$(CYAN)cleaning...$(NC)"
	@rm -rf ${OBJ_FR}
fclean: clean
	@rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re
