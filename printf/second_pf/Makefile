CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =  ft_printf.c \
		ft_printf_util.c \
		ft_isfunc.c \
		ft_memfunc.c \
		ft_putfunc.c \
		ft_itoa.c \
		ft_utoa.c \
		ft_utoh.c \
		ft_utop.c \
		ft_string.c \
		get_int.c \
		get_usint.c \
		get_shex.c \
		get_lhex.c \
		get_pointer.c \
		get_string.c \
		get_char.c \
		get_percent.c
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
