NAME		=	00-Polymorphism

CPPF		=	c++ $(FLAGS)
FLAGS		=	-Wall -Wextra -Werror -I./

HDR			=	ClassAnimal.hpp ClassCat.hpp ClassDog.hpp WrongCat.hpp WrongAnimal.hpp

SRCS		=	main.cpp ClassAnimal.cpp ClassCat.cpp ClassDog.cpp WrongCat.cpp WrongAnimal.cpp
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

re:				fclean	all

.PHONY:			all clean fclean re