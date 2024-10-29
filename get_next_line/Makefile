NAME = gnl
CFLAGS = -Wall -Wextra -Werror -g -I.
HEADER = get_next_line.h
SRC = get_next_line.c get_next_line_utils.c

OBJS = $(SRC:.c=.o)

%.o : %.c $(HEADER)
	cc $(CFLAGS) -c $<  -o $@

$(NAME) : $(OBJS)
	cc $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)
	rm -rf sample.txt
re:fclean $(NAME)

.PHONY: clean fclean  re