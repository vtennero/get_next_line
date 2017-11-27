#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int	ft_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	return (-1);
}

//a ajouter dans la libft

char	*ft_strndup(const char *s1, int n)
{
	char	*t;
	int		i;

	i = 0;
	t = (char *)malloc(sizeof(*t) * n + 1);
	if (!t)
		return (NULL);
	while (i < n)
	{
		t[i] = s1[i];
		i++;
	}
	return (t);
}

int	ft_parse(char **line)
{
	int	i;
	char	*str;
	/*static char	*stock;
	static int	k;

	if (k == 0)
	{
		stock = malloc(sizeof(char) * BUF_SIZE + 1);
		k++;
	}*/
	i = 0;
	/*if (k > 0 && stock != NULL)
		*line = ft_strjoin(stock, *line);
	*/str = *line;
	if (ft_strchr(*line, '\n') == NULL)
	{
		ft_putstr(*line);
		ft_putchar(10);
		return (0);
	}
	else
	{
		while ((str[i] != '\n') && (str[i] != '\0'))
			i++;
		//ft_memset(stock, '\0', i);
		//stock = ft_strchr(*line, '\n');
		*line = ft_strndup(str, i);
		ft_putstr("\nelse\n");	}
	ft_putstr(*line);
			ft_putchar(10);
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	int	ret;
	char	buf[BUF_SIZE +1];
	char	*tmp;

	if (!line)
		return (-1);
	*line = 0;
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		tmp = *line;
		buf[ret] = '\0';
		if (tmp)
			*line = ft_strjoin(*line, buf);
		else
			*line = ft_strdup(buf);
		if (ft_parse(line) == 1)
			return (1);
		free(tmp);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	fd;
	char	**line;
	int	i;

	i = 1;
	av++;
	line = malloc(700);
	ft_bzero(line, 700);
	if(ac)
	{
		fd = open(*av, O_RDONLY);
		while (i < 25)
		{
			get_next_line(fd, line);
			/*ft_putstr("***line ");
			ft_putnbr(i);
			ft_putstr("***\n");
			ft_putstr(*line);
			ft_putchar(10);
			*/i++;
		}
	}
	return(1);

/*
	char    *line;
    int     r;
    int     i;

    line = NULL;
    i = 0;
    while ((r = get_next_line(0, &line)) > 0)
        printf("%i: %s\n", ++i, line);
    return (r);*/
}