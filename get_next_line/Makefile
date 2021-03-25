
SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)

NAME = get_next_line.a

RM = rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

$(OBJS): ./get_next_line.h

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHOHY: all clean fclean re
