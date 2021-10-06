# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 17:56:13 by ekwon             #+#    #+#              #
#    Updated: 2021/10/06 13:57:59 by ekwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = pipex

SRCS_NAME = pipex.c util.c path.c command.c fix.c
SRCS_DIR = ./srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

LIB_NAME = ft
LIB_DIR = ./libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

$(NAME) : $(OBJS)
	make -C $(LIB_DIR) all
	$(CC) $(CFLAGS) -L$(LIB_DIR) -l$(LIB_NAME) $^ -o $@

$(SCRS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(LIB_DIR) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	rm -rf $(NAME) $(OBJS)

re : fclean all

.PHONY : all clean fclean re
