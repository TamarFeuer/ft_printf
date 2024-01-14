NAME = libftprintf.a

SRCS =	ft_printf.c ft_printer.c

OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJS)
	ar -cr $(NAME) $(OBJS) 

%.o:%.c ft_printf.h
	cc $(CFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re: fclean all

.PHONY:		all clean fclean re