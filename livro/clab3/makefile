NAME=Blasteroids
CC=gcc
CFLAGS=-Wall
LIBS=-lallegro
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) $(CFLAGS) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o $(NAME)
