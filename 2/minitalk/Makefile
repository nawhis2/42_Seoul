NAME = server client
SRCS_MAN = server.c client.c
OBJS_MAN = $(SRCS_MAN:.c=.o)
SRCS_BON = server_bonus.c client_bonus.c
OBJS_BON = $(SRCS_BON:.c=.o)
CLIENT_MAN = client.o
CLIENT_BON = client_bonus.o
SERVER_MAN = server.o
SERVER_BON = server_bonus.o
HEADER_MAN = minitalk.h
HEADER_BON = minitalk_bonus.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef BONUS
	SRCS = $(SRCS_BON)
	HEADER = $(HEADER_BON)
	CLIENT_OBJ = $(CLIENT_BON)
	SERVER_OBJ = $(SERVER_BON)
	EXE_DEPEND = MAKE_BONUS
else
	SRCS = $(SRCS_MAN)
	HEADER = $(HEADER_MAN)
	CLIENT_OBJ = $(CLIENT_MAN)
	SERVER_OBJ = $(SERVER_MAN)
	EXE_DEPEND = MAKE_MAN
endif

all : $(NAME) 

bonus : 
	make BONUS=1

$(NAME) : $(CLIENT_OBJ) $(SERVER_OBJ) $(EXE_DEPEND)
	$(MAKE) -C ./ft_printf
	$(MAKE) -C ./libft
	$(CC) -fsanitize=address -o client $(CLIENT_OBJ) ./ft_printf/libftprintf.a ./libft/libft.a
	$(CC) -fsanitize=address -o server $(SERVER_OBJ) ./ft_printf/libftprintf.a ./libft/libft.a
	rm -f MAKE_BONUS MAKE_MAN 
	touch $(EXE_DEPEND)

$(EXE_DEPEND) : 
	touch $@;

%.o : %.c
	$(CC) $(CFLAGS) -c $<

clean :
	$(MAKE) -C ./ft_printf clean;
	$(MAKE) -C ./libft clean;
	rm -f $(OBJS_BON) $(OBJS_MAN) MAKE_BONUS MAKE_MAN

fclean : clean
	$(MAKE) -C ./ft_printf fclean;
	$(MAKE) -C ./libft fclean;
	rm -f $(NAME) 

re : fclean all

.PHONY : all clean fclean re bonus