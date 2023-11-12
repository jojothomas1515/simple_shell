CC=gcc
FLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)


all: hsh clean

hsh: $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -g -o $@

$(OBJ): $(SRC)
	$(CC) -c -g $(FLAGS) $(SRC)

clean:
	rm -rf *.o
