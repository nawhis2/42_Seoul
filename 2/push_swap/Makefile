NAME = push_swap
BONUS = checker
SRCS = ft_main.c ft_rules.c ft_rules2.c ft_stack.c ft_utils.c ft_partition.c ft_qsort.c ft_greedysrt.c ft_split.c ft_libft.c ft_countcase.c case_hard_coding.c
OBJS = $(SRCS:.c=.o)
SRCS_BON = ft_checker_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c ft_strncmp_bonus.c ft_rules_bonus.c  ft_rules2_bonus.c ft_rules.c ft_rules2.c ft_stack.c ft_utils.c ft_partition.c ft_qsort.c ft_greedysrt.c ft_split.c ft_libft.c ft_countcase.c case_hard_coding.c
OBJS_BON = $(SRCS_BON:.c=.o)
CFLAGS = -Wall -Wextra -Werror
TMP_FILE = bonus

ifdef BONUS
	SRC = $(SRCS_BON)
	OBJ = $(OBJS_BON)
	HEADER = push_swap_bonus.h
else
	SRC = $(SRCS)
	OBJ = $(OBJS)
	HEADER = push_swap.h
endif

$(NAME) : $(OBJS)
	make -C ./ft_printf
	$(CC) $(CFLAGS) -g -o $@ $^ ./ft_printf/libftprintf.a

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -g -c -o $@ $<

bonus : $(OBJ)
	make -C ./ft_printf
	$(CC) $(CFLAGS) -g -o $(BONUS) $^ ./ft_printf/libftprintf.a
	touch $(TMP_FILE)

all : $(NAME)

clean :
	make -C ./ft_printf clean
	rm -f $(OBJS) $(OBJS_BON) $(TMP_FILE) 
	

fclean : clean
	make -C ./ft_printf fclean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all clean fclean re
