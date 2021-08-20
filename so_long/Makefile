# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ekwon <ekwon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/17 15:32:37 by ekwon             #+#    #+#              #
#    Updated: 2021/08/20 20:01:31 by ekwon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra

NAME = so_long

SRCS_NAME = main.c map.c move.c image.c util.c error.c
SRCS_DIR = ./srcs
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_NAME))
OBJS = $(SRCS:.c=.o)

LIB_NAME = ft
LIB_DIR = ./libft
LIB = $(addprefix $(LIB_DIR)/, libft.a)

MLX_NAME = mlx
MLX_DIR = ./mlx
MLX = $(addprefix $(MLX_DIR)/, libmlx.dylib)

INCLUDES = includes/

$(NAME) : $(OBJS)
	make -C $(LIB_DIR) all
	make -C $(MLX_DIR) all
	$(CC) $(CFLAGS) -I$(INCLUDES) -L$(LIB_DIR) -l$(LIB_NAME) -L$(MLX_DIR) -l$(MLX_NAME) \
        $^ -o $@
	@install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib $(NAME)

$(SRCS_DIR)/%.o : $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INCLUDES) -I$(MLX_DIR) -I$(LIB_DIR) -c $< -o $@

all : $(NAME)

clean :
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean :
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(NAME) $(OBJS)

re : fclean all

bonus : all

.PHONY : all clean fclean re bonus