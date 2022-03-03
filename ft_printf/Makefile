SRCS		= ft_printf.c ft_putnbr_fd.c ft_print_string.c ft_putchar_fd.c ft_print_hex.c \
			ft_putnbr_un.c ft_print_point.c 

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

NAME		= libftprintf.a

all:		$(NAME)

$(NAME): 	$(OBJS)
	ar r $(NAME) $(OBJS)

clean: 
	rm -f $(OBJS)

fclean: 	clean 
	rm -f $(NAME) 

re:			fclean all

.PHONY: 	all clean fclean re
