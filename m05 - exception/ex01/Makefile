NAME		=	01-form

CPPF		=	c++ $(FLAGS)
# CPPF		=	clang++ $(FLAGS)

FLAGS		=	-Wall -Wextra -Werror -I./

HDR			=   Bureaucrat.hpp Form.hpp

SRCS		=	main.cpp Bureaucrat.cpp Form.cpp

OBJS		=	$(SRCS:.cpp=.o)

%.o:			%.cpp $(HDR)
					@$(CPPF) -std=c++98 -c $< -o $@
					@echo "$(GREEN)"$@ "compilled$(ENDCOLOR)"

GREEN		=	\033[92m
ENDCOLOR	=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJS)
				@$(CPPF) $(OBJS) -o $(NAME)
				@echo "$(GREEN)$(NAME) is compiled $(ENDCOLOR)"

clean:		;	@rm -f $(OBJS)

fclean:			clean	;	@rm -f $(NAME)

re:				fclean	all

.PHONY:			all clean fclean re