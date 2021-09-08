#SETUP
NAME		= megaphone
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror
RM			= rm -f

#FILES
SRCS		= $(NAME).cpp
OBJS		= $(SRCS:.cpp=.o)

#COMMANDS
all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)$(NAME) cleaned!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) deleted!$(DEFAULT)"

re:			fclean all

#EXTRA
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m

.PHONY:		all clean fclean re