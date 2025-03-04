CC			= c++
FLAGS		= -std=c++98 -Wall -Wextra -Werror -g
NAME		= ex04
SRCS		= main.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $< 

clean:
	rm -f $(OBJS) *.replace

fclean:
	rm -f $(NAME) $(OBJS) *.replace

re: fclean all

.PHONY: all clean fclean re