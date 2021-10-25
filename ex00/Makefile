SRCS = main.cpp Fixed.cpp
FLAGS = -Wall -Werror -Wextra -std=c++98
NAME = Fixed_Init

all : $(NAME)

$(NAME): $(SRCS)
	clang++ $(FLAGS) $(SRCS) -o $(NAME)
clean:
	rm -Rf $(NAME)
fclean : clean

re : fclean all