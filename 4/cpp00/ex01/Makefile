CC			= c++
FLAGS		= -std=c++98 -Wall -Wextra -Werror
NAME		= PhoneBook 
SRCS		= main.cpp PhoneBook.cpp
OBJS		= $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $< 


clean:
	rm -f $(OBJS)

fclean:
	rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re