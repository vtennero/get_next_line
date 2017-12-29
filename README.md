# get_next_line

The goal of the project is to to write a function that reads a line ending with a newline character from a file descriptor, thus allowing to save/use a given text file line by line if called in a loop.

## Installing

Clone the repository and: 

```
make
```

### Linux Support

In the Makefile, simply replace :

```
FLAGS = -Wall -Werror -Wextra
```

With :

```
#FLAGS = -Wall -Wno-empty-body -Wno-unused -Wextra
```

## Running the tests

The easiest way is to add a main function in get_next_line.c that calls get_next_line, for example like this:

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

Then you can run the executable with a file of your choice:

```
./test_gnl [file]
```

Note that stdin is also supported.

### TN_test_GNL

I have created my own test program : [TN_test_GNL](https://github.com/vtennero/TN_test_GNL)

It tests 15 relevant examples of text, with 5 different buff sizes (1, 2, 5, 1,000 and 1,000,000), from files and standard input.

For each test, the program also checks memory leaks using the native leaks tool from Mac and valgrind (both only supported on the Macs at 42)

## Additional Resources

Instructions : [Subject](http://bit.ly/2Dt5LOS)

My test program : [TN_test_GNL](https://github.com/vtennero/TN_test_GNL)

Another test program (not made by me) : [42FC](https://github.com/jgigault/42FileChecker)

## Author

* **Victor Tenneroni** - [Website](http://victor-tenneroni.com/)
