CC			= c++
FLAGS		= -MMD -MP -std=c++98 -Wall -Wextra -Werror
NAME		= ex03
SRCNAME		= main AForm Bureaucrat PresidentialPardonForm RobotomyRequestForm ShrubberyCreationForm Intern
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
	rm -f $(OBJS) $(DEP) *_shrubbery

fclean:
	rm -f $(NAME) $(OBJS) $(DEP) *_shrubbery

re: fclean all

.PHONY: all clean fclean re