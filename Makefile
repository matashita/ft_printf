CC = cc
CFLAG = -Wall -Wextra -Werror
SRCS = ft_print.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putunbr_fd.c ft_print_func.c
OBJS = $(SRCS:%.c=%.o)
AR = ar r
NAME = libftprintf.a

all:	$(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY :  all clean fclean re