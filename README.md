# get_next_line

get_next_line is a function that reads a line ending with a newline character from a file descriptor, thus allowing to save/use a given text file line by line if called in a loop.

## Installing & running the tests

### TN_test_GNL

I have created my own test program : [TN_test_GNL](https://github.com/vtennero/TN_test_GNL)

It tests 15 relevant examples of text, with 5 different buff sizes (1, 2, 5, 1,000 and 1,000,000), from files and standard input. For each test, the program also checks memory leaks using the native leaks tool from Mac and valgrind (both only supported on the Macs at 42).

To install it, simply put the content of the TN_test_GNL folder in your get_next_line folder, then do :

```
sh TN_test_GNL.sh
```

### Other method

Another method is to add a main.c that calls get_next_line, for example like this:

```
#include <stdio.h>

int	main(int ac, char **av)
{
	int		fd;
	char	**line;
	int		return_value;

	line = (char**)malloc(sizeof(char*));
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		while ((return_value = get_next_line(fd, line)) == 1)
		{
			printf("%s\n", *line);
			free(*line);
		}
		free(*line);
		free(line);
		close(fd);
	}
	return (0);
}
```

Then do :

```
make -C libft/ fclean && make -C libft/
clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
```

Then you can run the executable with a file of your choice:

```
./test_gnl [file]
```

## Additional Resources

Instructions : [Subject](https://www.dropbox.com/s/dum2raheu2wfes7/get_next_line.en.pdf?dl=0)

My test program : [TN_test_GNL](https://github.com/vtennero/TN_test_GNL)

Another test program (not made by me) : [42FC](https://github.com/jgigault/42FileChecker)

## Author

* **Victor Tenneroni** - [Website](http://victor-tenneroni.com/)
