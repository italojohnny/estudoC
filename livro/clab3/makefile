NAME=blasteroids
CC=gcc
#CFLAGS=-O3 -W -Wall -Wextra -Werror
LIBS=-lallegro -lallegro_primitives -lallegro_ttf -lallegro_font

#SOURCES=$(wildcard *.c)
#OBJECTS=$(SOURCES:.c=.o)

#all: $(NAME)
#	./$(NAME)

#$(NAME): $(OBJECTS)
#	$(CC) $(OBJECTS) $(LIBS) $(CFLAGS) -o $@

#%.o: %.c
#	$(CC) -c $(LIBS) $(CFLAGS) $< -o $@


spaceship.o: spaceship.c spaceship.h
	$(CC) -c spaceship.c $(LIBS) $(CFLAGS) -o spaceship.o

blast.o: blast.c blast.h
	$(CC) -c blast.c $(LIBS) $(CFLAGS) -o blast.o

asteroid.o:	asteroid.c asteroid.h
	$(CC) -c asteroid.c $(LIBS) $(CFLAGS) -o asteroid.o

blasteroids.o: blasteroids.c
	$(CC) -c blasteroids.c $(LIBS) $(CFLAGS) -o blasteroids.o

blasteroids: blasteroids.o asteroid.o blast.o spaceship.o
	$(CC) blasteroids.o asteroid.o blast.o spaceship.o $(LIBS) $(CFLAGS) -o blasteroids

all: blasteroids
	./blasteroids

clear:
	clear
	rm -f *.o $(NAME)
