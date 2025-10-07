NAME = a.out
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) Fixed.hpp
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re