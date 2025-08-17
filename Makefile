NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c stack_func.c sort.c utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re