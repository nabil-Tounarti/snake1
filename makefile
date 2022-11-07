OBJS	= main.o snake.o
SOURCE	= main.c snake.c
HEADER	= snake.h
OUT	=  prog
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS) -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

main.o: main.c
	$(CC) $(FLAGS) main.c -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net

snake.o: snake.c
	$(CC) $(FLAGS) snake.c -lSDL2 -lSDL2_gfx -lSDL2_image -lSDL2_ttf -lSDL2_mixer -lSDL2_net


clean:
	rm -f $(OBJS) $(OUT)
