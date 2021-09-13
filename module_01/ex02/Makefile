#SETUP
NAME		= prog
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -MD -std=c++98
RM			= rm -f

#FILES
SRCS_DIR	=
FLS			= main.cpp
SRCS		= $(addprefix $(SRCS_DIR), $(FLS))
OBJS		= $(SRCS:.cpp=.o)
DEPS		= $(SRCS:.cpp=.d)

#COMMANDS
all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CXX) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
			@$(RM) $(OBJS) $(DEPS)
			@echo "$(YELLOW)$(NAME) cleaned!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) deleted!$(DEFAULT)"

re:			fclean all

#RULES
-include $(DEPS)

#EXTRA
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m

.PHONY:		all clean fclean re