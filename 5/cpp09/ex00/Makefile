CC			= c++
FLAGS		= -MMD -MP -std=c++11 -Wall -Wextra -Werror -g
NAME		= btc
SRCNAME		= main BitcoinExchange
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