CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =  ft_atoi.c ft_isfunc.c ft_memfunc.c ft_printf.c ft_putfunc.c get_int.c ft_itoa.c ft_strcpy.c ft_ritoa.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)

fclean :
	rm -f $(NAME) $(OBJS)

re :
	make fclean
	make all
