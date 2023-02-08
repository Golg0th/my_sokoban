##
## EPITECH PROJECT, 2023
## my_sokobn
## File description:
## Makefile
##

NAME = my_sokoban

SRC	= $(wildcard src/*.c)

OBJ	= $(SRC:.c=.o)

CFLAGS = -g

all: $(NAME)

$(NAME): $(OBJ)
	gcc -g $(OBJ) -Wall -Wextra -lncurses -o $(NAME) -I includes

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
