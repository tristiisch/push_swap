# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 12:37:16 by tglory            #+#    #+#              #
#    Updated: 2021/05/13 17:50:05 by ksam             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC 				= 	gcc
NAME    		=	push_swap
NAME_CHECKER	=	checker
NAME_RANDOMIZE	=	randomize
LIB_PATH		=	libft/libft.a get_next_line/get_next_line.a
NORM_DIRS		=	srcs/ includes/ get_next_line/ libft/
INCLUDES		=	$(wildcard includes/*.h)
SRCS			=	$(wildcard srcs/*.c)
SRCS_PUSH_SWAP	=	srcs/push_swap/main.c
SRCS_CHECKER	=	$(wildcard srcs/checker/*.c)
SRCS_RANDOMIZE	=	srcs/randomize/main.c
OBJS			=	$(SRCS:.c=.o)
OBJS_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)
OBJS_RANDOMIZE	=	$(SRCS_RANDOMIZE:.c=.o)
CFLAGS			=	-Wextra -Wall -g3 -fsanitize=address #-Werror

all: $(NAME) $(NAME_CHECKER)

$(NAME): $(OBJS) $(OBJS_PUSH_SWAP) $(INCLUDES)
	make -C libft
	make -C get_next_line
	$(CC) ${CFLAGS} $(OBJS) $(OBJS_PUSH_SWAP) $(LIB_PATH) -o $(NAME)

$(NAME_CHECKER): $(OBJS) $(OBJS_CHECKER) $(INCLUDES)
	make -C libft
	make -C get_next_line
	$(CC) ${CFLAGS} $(OBJS) $(OBJS_CHECKER) $(LIB_PATH) -o $(NAME_CHECKER)

$(NAME_RANDOMIZE): $(OBJS) $(OBJS_RANDOMIZE) $(INCLUDES)
	make -C libft
	make -C get_next_line
	$(CC) ${CFLAGS} $(OBJS) $(OBJS_RANDOMIZE) $(LIB_PATH) -o $(NAME_RANDOMIZE)

.c.o:
		${CC} ${CFLAGS} -c $< -o $@
clean:
	make $@ -C libft
	make $@ -C get_next_line
	rm -f $(OBJS)
	rm -f $(OBJS_PUSH_SWAP)
	rm -f $(OBJS_CHECKER)
	rm -f $(OBJS_RANDOMIZE)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_CHECKER)
	rm -f $(NAME_RANDOMIZE)

re:
	make fclean
	make all

norminette:
	norminette $(NORM_DIRS)

norm: norminette

.PHONY: all clean fclean re norm norminette start
