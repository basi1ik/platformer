compile: build run

build:
	gcc src/*.c \
	src/sdl/*.c \
	-o out/game \
	`pkg-config --cflags --libs sdl3 sdl3-image`

run:	
	out/game

clean:
	rm out/game
