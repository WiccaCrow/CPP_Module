NAME		=	BSP

CPPF		=	c++ $(FLAGS)
FLAGS		=	-Wall -Wextra -Werror -I./

HDR			=	Fixed.hpp Point.hpp

SRCS		=	main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS		=	$(SRCS:.cpp=.o)

%.o:			%.cpp %.hpp
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

re:				fclean all

.PHONY:			all clean fclean re