CFILES = create_stack.c error_checker.c prepare_nodes_a.c prepare_nodes_b.c \
	push_command.c rotate_command.c reverse_rotate_command.c sorting.c \
	stack_functions_1.c stack_functions_2.c swap_command.c

PUSH_SWAP_FILES = $(CFILES) main.c
CHECKER_FILES = $(CFILES) checker.c

PUSH_SWAP_OBJECTS = $(filter-out checker.o, $(CFILES:.c=.o) main.o)
CHECKER_OBJECTS = $(filter-out main.o, $(CFILES:.c=.o) checker.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
CHECKER = checker

all: $(NAME)

$(NAME): $(PUSH_SWAP_OBJECTS)
	$(CC) $(CFLAGS) $(PUSH_SWAP_OBJECTS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(CHECKER)

$(CHECKER): $(CHECKER_OBJECTS)
	$(CC) $(CFLAGS) $(CHECKER_OBJECTS) -o $(CHECKER)

fclean: clean
	rm -f $(NAME) $(CHECKER)

clean:
	rm -f $(PUSH_SWAP_OBJECTS) $(CHECKER_OBJECTS)

re: fclean all

.PHONY: all fclean clean re bonus
