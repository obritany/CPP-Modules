#SETUP
NAME		= PhoneBook
CXX			= clang++
CXXFLAGS	= -Wall -Wextra -Werror -MD
RM			= rm -f

#FILES
SRCS_DIR	= sources/
# OBJS_DIR	= $(SRCS_DIR)objs/
FLS			= main.cpp PhoneBook.cpp Contact.cpp
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

# %.o:		%.cpp
# 			mkdir -p $(OBJS_DIR)
# 			$(CXX) $(CXXFLAGS) -c $< -o $(OBJS_DIR)$(@F)

#EXTRA
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m

.PHONY:		all clean fclean re