all:
	gcc -Wall -Wextra -Wno-unused-parameter -g -o main main.c hash.c forward_list.c
clean:
	rm -f main
