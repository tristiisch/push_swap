# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 12:37:16 by tglory            #+#    #+#              #
#    Updated: 2021/03/31 05:34:21 by tglory           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC 			= 	gcc
NAME    	=	push_swap
LIB_PATH	=	libft/libft.a get_next_line/get_next_line.a
NORM_DIRS	=	srcs/ includes/ get_next_line/ libft/
INCLUDES	=	$(wildcard includes/*.h)
SRCS		=	$(wildcard srcs/*.c)
OBJS		=	$(SRCS:.c=.o)
CFLAGS		=	-Wextra -Wall #-Werror

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

start:
	./$(NAME)

norminette:
	norminette $(NORM_DIRS)

norm: norminette

.PHONY: all clean fclean re norm norminette start
