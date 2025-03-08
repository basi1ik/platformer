compile: build run

build:
	gcc -o out/game src/*.c `pkg-config --cflags --libs sdl3 sdl3-image`

run:	
	out/game

clean:
	rm out/game
