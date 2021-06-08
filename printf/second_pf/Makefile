CC = gcc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
SRCS =  ft_atoi.c ft_isfunc.c ft_memfunc.c ft_printf.c ft_putfunc.c get_int.c
OBJS = $(SRCS:.c=.o)
all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean :
	rm -f $(OBJS)
	make clean -C ./libft

fclean :
	rm -f $(NAME) $(OBJS)
	make fclean -C ./libft

re :
	make fclean
	make all