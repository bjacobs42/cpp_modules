NAME		:= megaphone
LIBFT		:= libft
SRC_DIR		:= src/
OBJ_DIR		:= obj/
#INCLUDES	:= 
CC			:= c++
CFLAGS		:= -Wall -Werror -Wextra -std=c++98

# Reset
NC		:= \033[0m# 		Text Reset

# Regular Colors
BLACK	:= \033[0;30m#	Black
RED		:= \033[3;31m#	Red
GREEN	:= \033[3;32m#	Green
BLD_GRN	:= \033[1;32m#	Green
YELLOW	:= \033[3;33m#	Yellow
BLUE	:= \033[1;34m#	Blue
PURPLE	:= \033[3;35m#	Purple
BLD_PUR	:= \033[1;35m#	Purple but bold
CYAN	:= \033[3;36m#	Cyan
WHITE	:= \033[1;37m#	White

all: $(NAME)

$(NAME): megaphone.cpp
	@echo "$(PURPLE)============================[$(BLD_PUR)$(NAME)$(NC)$(PURPLE)]============================$(NC)"
	@echo "$(GREEN)creating $@...$(NC)"
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "$(BLD_GRN)done!$(NC)"

clean:

fclean: clean
	@echo "$(CYAN)cleaning...$(NC)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
