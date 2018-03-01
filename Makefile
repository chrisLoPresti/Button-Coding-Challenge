all: evalexpression

evalexpression: evalexpression.c

	gcc -g -Wall -Werror -fsanitize=address evalexpression.c -o evalexpression

clean:
	rm -rf evalexpression

