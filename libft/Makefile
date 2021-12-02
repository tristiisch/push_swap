# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tglory <tglory@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/26 17:55:35 by tglory            #+#    #+#              #
#    Updated: 2021/12/02 14:00:25 by tglory           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_isdigit.c \
		ft_memset.c	\
		ft_strlcat.c \
		ft_substr.c \
		ft_isprint.c \
		ft_putchar_fd.c \
		ft_strlcpy.c \
		ft_tolower.c \
		ft_atoi.c \
		ft_itoa.c \
		ft_putendl_fd.c \
		ft_strlen.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_memccpy.c \
		ft_putstr_fd.c \
		ft_strmapi.c \
		ft_calloc.c \
		ft_realloc.c \
		ft_memchr.c \
		ft_split.c \
		ft_strncmp.c \
		ft_isalnum.c \
		ft_memcmp.c \
		ft_strchr.c \
		ft_strnstr.c \
		ft_isalpha.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strrchr.c \
		ft_isascii.c \
		ft_memmove.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_putnbr_fd.c \
		ft_strmapi.c \
		ft_strcmp.c \
		ft_strichr.c \
		ft_strncmp.c \
		ft_strcat.c \
		ft_strcpy.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

SRC_BONUS = ft_lstadd_front_bonus.c \
			ft_lstnew_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c

O_FILES =	${SRC:.c=.o}

O_BONUS =	${SRC_BONUS:.c=.o}

CC 		=	gcc

CFLAGS	=   -Wall -Wextra -Werror

INCLUDE =	libft.h

$(NAME) :	$(O_FILES)
			ar rcs $(NAME) $(O_FILES)
			ranlib $(NAME)

%.o:	%.c $(INCLUDES)
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

clean:
			rm -f $(O_FILES) $(O_BONUS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all

bonus:		$(NAME) $(O_BONUS)
			ar rcs $(NAME) $(O_BONUS)

.PHONY: all clean fclean re bonus