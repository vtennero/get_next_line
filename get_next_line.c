#include "get_next_line.h"
#include "libft.h"
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

//a ajouter dans la libft

int		ft_eol(char *str)
{
	int	i;

	i = 0;
			while (str[i] != '\n' && str[i])
				i++;
			if (str[i] == '\n')
			{
				str[i] = '\0';
				return (i);
			}
			else
				return (-1);
}

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
	t[n] = '\0';
	return (t);
}

int	ft_parse(char **line, char **hello, int l)
{
	int	i;

	i = 0;
	if (*hello)
	{
		*line = ft_strjoin(*hello, *line);
		ft_strdel(hello);
	}
	if (ft_strchr(*line, '\n') == NULL)
	{
		return (0);
	}
	else
	{
		i = ft_eol(*line);
		*hello = ft_strsub(*line, i + 2, l - i);
		*line = ft_strndup(*line, i);
	}
	return (1);
}

int	get_next_line(int const fd, char **line)
{
	int	ret;
	char	buf[BUFF_SIZE +1];
	char	*tmp;
	static char	*hello = NULL;
	static int	l;

	l = 0;
	if (!line || BUFF_SIZE < 0 || fd < 0)
		return (-1);
	*line = ft_strnew(1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		l = l + ret;
		tmp = *line;
		buf[ret] = '\0';
		if (tmp)
			*line = ft_strjoin(*line, buf);
		else
			*line = ft_strdup(buf);
		if (ft_parse(line, &hello, l) == 1)
			return (1);
		free(tmp);
	}
	if ((ret == 0))
		return (1);
	if (ret < 0)
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac)
	{
	fd = open(av[1], O_RDONLY);
	while ((get_next_line(fd, &line) == 1) && (ft_strlen(line) > 0))
	{			
		ft_putstr(line);
		ft_putchar(10);
	}
	close(fd);
	}
return (0);
}
/*
	char    *line;
    int     r;
    int     i;

    line = NULL;
    i = 0;
    while ((r = get_next_line(0, &line)) > 0)
        printf("%i: %s\n", ++i, line);
    return (r);*/