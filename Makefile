# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ksam <ksam@student.42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/04 12:37:16 by ksam              #+#    #+#              #
#    Updated: 2021/05/22 20:10:55 by ksam             ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC 				= 	gcc
NAME    		=	push_swap
NAME_CHECKER	=	checker
NAME_RANDOMIZE	=	randomize
LIB_PATH		=	libft/libft.a
NORM_DIRS		=	srcs/ includes/ libft/
INCLUDES		=	includes/push_swap.h
SRCS			=	srcs/algo.c \
					srcs/basic_sort.c \
					srcs/checker_particularity_II.c \
					srcs/checker_particularity.c \
					srcs/doubly_linked_list.c \
					srcs/ft_args.c \
					srcs/ft_atoi_utimate.c \
					srcs/ft_error.c \
					srcs/ft_initialize.c \
					srcs/get_big_index.c \
					srcs/instructions_utils.c \
					srcs/jump_to_index.c \
					srcs/jump_to_index2.c \
					srcs/perfect_shot.c \
					srcs/push_swap_utils.c \
					srcs/random.c \
					srcs/sort.c \
					srcs/stack.c \
					srcs/stack2.c \
					srcs/stack3.c

SRCS_PUSH_SWAP	=	srcs/push_swap/main.c \
					srcs/push_swap/unit_tests.c

SRCS_CHECKER	=	srcs/checker/checker.c \
					srcs/checker/free_functions.c \
					srcs/checker/instructions_initializor.c \
					srcs/checker/main.c \
					srcs/checker/transform_arg_to_array.c

SRCS_RANDOMIZE	=	srcs/randomize/main.c
OBJS			=	$(SRCS:.c=.o)
OBJS_PUSH_SWAP	=	$(SRCS_PUSH_SWAP:.c=.o)
OBJS_CHECKER	=	$(SRCS_CHECKER:.c=.o)
OBJS_RANDOMIZE	=	$(SRCS_RANDOMIZE:.c=.o)
# CFLAGS			=	-Wextra -Wall -Werror
CFLAGS			=	-Wextra -Wall -g3 -fsanitize=address

all: $(NAME) $(NAME_CHECKER)

$(NAME): $(OBJS) $(OBJS_PUSH_SWAP) $(INCLUDES)
	make -C libft
	$(CC) ${CFLAGS} $(OBJS) $(OBJS_PUSH_SWAP) $(LIB_PATH) -o $(NAME)

$(NAME_CHECKER): $(OBJS) $(OBJS_CHECKER) $(INCLUDES)
	make -C libft
	$(CC) ${CFLAGS} $(OBJS) $(OBJS_CHECKER) $(LIB_PATH) -o $(NAME_CHECKER)

$(NAME_RANDOMIZE): $(OBJS) $(OBJS_RANDOMIZE) $(INCLUDES)
	make -C libft
	$(CC) ${CFLAGS} $(OBJS) $(OBJS_RANDOMIZE) $(LIB_PATH) -o $(NAME_RANDOMIZE)

.c.o:
		${CC} ${CFLAGS} -c $< -o $@
clean:
	make $@ -C libft
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

random: $(NAME_RANDOMIZE)

.PHONY: all clean fclean re random
