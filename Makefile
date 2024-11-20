CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

# BSRCS =
# BOBJS = $(BSRCS .c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(NAME)
	ar -rcs $(NAME) $(BOBJS)

clean :
	rm -rf $(OBJS)$(BOBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
.PHONY: all clean fclean bonus
