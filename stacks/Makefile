CC=gcc
CFLAGS=-Iinclude

SRC=$(wildcard src/*.c)

all: program

program: $(SRC)
	mkdir -p build
	$(CC) $(CFLAGS) -o build/$@ $^

clean:
	rm -R build/
