NAME		= hi
CFLAGS		= -Wall -Werror -Wextra
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

SRC_FILES	:= main.cpp

all: ${NAME}

$(NAME): $(SRC_FILES)
	@echo "$(GREEN)creating $@...$(NC)"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(BLD_GRN)done!$(NC)"

clean:
	@echo "$(CYAN)cleaning...$(NC)"
fclean: clean
	@rm -f ${NAME}
re: fclean all

.PHONY: all clean fclean re
