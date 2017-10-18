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
	/*ft_putstr("yo");
	while (t)
	{
		t[i] = '\0';
		i++;
	}*/
	return (t);
}


int	get_next_line(int const fd, char **line)
{
	int	ret;
	char	buf[BUF_SIZE +1];
	char	*str;
	int		i;
	int		c;
	int		j;
	int		total;
	//static char	*stock;

	j = 0;
	i = 1;
	c = 0;
	total = 0;
	str = NULL;
	if (!line)
		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE)) != 0)
	{
		if (i == 1)
		{
			if (ft_check(buf) == -1)
			{
				//ft_putstr("pas de backslash n \n");
				str = ft_strdup(buf);
			}
			else
			{
				str = ft_strndup(buf, ft_check(buf));
				c = 1;
				//stock = ft_strchr(buf, '\n');
			}
		}
		else
		{
			if (ft_check(buf) == -1)
				{
				//ft_putstr("pas de backslash n \n");

				str = ft_strjoin(str, ft_strdup(buf));

				}
			else
			{
				str = ft_strjoin(str, ft_strndup(buf, ft_check(buf)));
				c = 1;
				//stock = ft_strchr(buf, '\n');
			}
		}
		//stock = ft_strchr(buf, '\n');
		if (c == 1)
		{
			*line = str;
			//ft_putstr("stock: ");
			//if (stock)
			//ft_putstr(stock);
			return (0);
		}
		i++;
		total = total + ret;
	}
	if (ret < BUF_SIZE && i > 1)
		{
		j = total;
	while (j < i * BUF_SIZE)
				{
					str[j] = '\0';
					j++;
				}
		}
	*line = str;
	//ft_putstr("stock: ");
	//ft_putstr(stock);
	return(1);
}
//boucle while no \0
//boucle while no \n
//stocker le surplus apres le \n
//variable statique pour stocker le contenu des phases de read
//malloc sur line ?
//strjoin pour concatener les strings dans line
//return line

//ou bien: tout lire et tout enregistrer, faire un strsplit pour les \n

//lecture du fd qq soit le buffer, mettons : "salut les gars\nca "
//detection du \n
//copie du string lu (buf) up to n
//stockage de: ca via strsub
//line = salut les gars\0
//renvoi de 1
//detection du \n
//copie up to \0
//return 0

//utilite de strrchr: renvoyer l'adresse apres le \n ?

int	main()
{
	int	fd;
	char	**line;

	av++;
	line = malloc(25000);
	ft_bzero(line, 25000);
	if(ac)
	{
		fd = open(*av, O_RDONLY);
		get_next_line(fd, line);
		//ft_putstr("\n***line : \n");
		ft_putstr(*line);
		//get_next_line(fd, line);
		//ft_putstr("\n***line : \n");
		//ft_putstr(*line);
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