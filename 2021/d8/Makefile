NAME = a.out
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

run: all
	./$(NAME) input.txt

test: all
	./$(NAME) input_test.txt

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: run test all clean fclean re
