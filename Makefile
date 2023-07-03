NAME = pipex
CC = gcc
CFLAGS = -g -Wall -Werror -Wextra
HEADER = pipex.h 

SRC = utils.c \
		pipex.c \
		utils_string.c \
		utils_path_free.c \
		exec.c \
		utils_path_help.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<

all: $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re

norminette:
	norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADER)
