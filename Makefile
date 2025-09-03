NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = cost_ab.c cost_ba.c main.c sort_cases.c move.c sort.c stack_func_1.c stack_func_2.c  stack_func_3.c stack_func.c \
utils.c utils1.c utils2.c utils3.c 
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