CC			= c++
FLAGS		= -MMD -MP -std=c++98 -Wall -Wextra -Werror -g
NAME		= ex00
SRCNAME		= main Bureaucrat
SRCS		= $(addsuffix .c, $(SRCNAME))
OBJS		= $(addsuffix .o, $(SRCNAME))
DEP			= $(addsuffix .d, $(SRCNAME))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

-include $(DEP)

%.o:%.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(DEP)

fclean:
	rm -f $(NAME) $(OBJS) $(DEP)

re: fclean all

.PHONY: all clean fclean re