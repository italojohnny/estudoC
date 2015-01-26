NAME=blasteroids
CC=gcc
CFLAGS=-Wall
LIBS=-lallegro -lallegro_primitives -lallegro_image -lallegro_ttf -lallegro_font

SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)

all: $(NAME)
	./$(NAME)
$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) $(CFLAGS) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f *.o $(NAME)
