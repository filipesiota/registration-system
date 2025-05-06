CC=gcc
CFLAGS=-Iinclude

SRC=$(wildcard src/*.c)

all: program

program: $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -o build/$@ $^

sanitize: $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -fsanitize=address -o build/program $^

clean:
	rm -R build/
