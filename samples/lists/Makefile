CC=gcc
CFLAGS=-Iinclude

SRC_COMMON=src/menu.c src/task.c src/util.c
SRC_ARRAY_LIST=src/task_array_list.c
SRC_LINKED_LIST=src/task_linked_list.c

all: main_array_list_program main_linked_list_program

main_array_list_program: main_array_list/main_array_list.c $(SRC_ARRAY_LIST) $(SRC_COMMON)
	$(CC) $(CFLAGS) -o $@ $^

main_linked_list_program: main_linked_list/main_linked_list.c $(SRC_LINKED_LIST) $(SRC_COMMON)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f main_array_list_program main_linked_list_program
