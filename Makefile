# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 12:37:16 by tglory            #+#    #+#              #
#    Updated: 2021/03/25 16:51:18 by tglory           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC 			= 	gcc
NAME    	=	push_swap
LIB_PATH	=	libft/libft.a get_next_line/get_next_line.a
INCLUDES	=	$(wildcard includes/*.h)
SRCS		=	$(wildcard srcs/*.c)
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	make -C libft
	make -C get_next_line
	$(CC) ${CFLAGS} $(OBJS) $(LIB_PATH) -o $(NAME)

.c.o:
		${CC} ${CFLAGS} -c $< -o $@
clean:
	make $@ -C libft
	make $@ -C get_next_line
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
