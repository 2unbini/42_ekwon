# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/06 14:13:09 by ekwon             #+#    #+#              #
#    Updated: 2021/07/06 14:18:32 by ekwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

CC = gcc
CFLAG =	-Wall -Wextra -Werror

RM = rm -f
AR = ar
ARFLAG = crs

INCLUDES = ./libft.h

SRCS_1 = \
	   ft_atoi.c \
	   ft_bzero.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isalnum.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strchr.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_calloc.c \
	   ft_strdup.c

SRCS_2 = \
		 ft_substr.c \
		 ft_strjoin.c \
		 ft_strtrim.c \
		 ft_split.c \
		 ft_itoa.c \
		 ft_strmapi.c \
		 ft_putchar_fd.c \
		 ft_putstr_fd.c \
		 ft_putendl_fd.c \
		 ft_putnbr_fd.c

SRCS_BONUS = \
			 ft_lstnew.c \
			 ft_lstadd_front.c \
			 ft_lstsize.c \
			 ft_lstlast.c \
			 ft_lstadd_back.c \
			 ft_lstdelone.c \
			 ft_lstclear.c \
			 ft_lstiter.c \
			 ft_lstmap.c

SRCS = $(SRCS_1) $(SRCS_2)

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

ifdef WITH_BONUS
	OBJ_FILES = $(OBJS) $(OBJS_BONUS)
else
	OBJ_FILES = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(AR) $(ARFLAG) $@ $^

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CFLAG) -c $< -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus
