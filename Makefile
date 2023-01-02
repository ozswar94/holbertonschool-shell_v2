NAME = hsh
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89 -g
SRC := $(wildcard src/*.c)
INC = include
RM = rm -rf 
OBJ = $(SRC:%.c=%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(NAME)

oclean:
	$(RM) $(OBJ)

fclean: clean oclean

re: fclean all

%.o:%.c
	$(CC) -I $(INC) $(CFLAGS) -c -o $@ $<
