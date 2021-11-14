NAME		=	account

CPPF		=	clang++ $(FLAGS)
FLAGS		=	 -g -I./
# FLAGS		=	-Wall -Wextra -Werror -I./

HDR			=	Account.hpp

SRCS		=	Account.cpp test.cpp
OBJS		=		$(SRCS:.cpp=.o)
%.o:			%.cpp
				# @$(CPPF) -std=c++98 -c $< -o $@
				@$(CPPF) -c $< -o $@
				@echo "$(GREEN)"$@ "compilled$(ENDCOLOR)"


GREEN		=	\033[92m
ENDCOLOR	=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CPPF) $(OBJS) -o $(NAME)
				@echo "$(GREEN)$(NAME) is compiled $(ENDCOLOR)"

clean:		;	@rm -f $(OBJS)

fclean:			clean	;	@rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re