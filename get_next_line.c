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
	while (str[i] != '\n')
		i++;
	return (i);
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


int	get_next_line(int const fd, char** line)
{
	int	ret;
	char	buf[BUF_SIZE +1];
	int	i;
	int	k;
	char	*str;

	i = 0;
	k = 0;
	str = malloc(250);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
			while (i < ret)
			{
				if (buf[i] == '\n')
				{
					k = BUF_SIZE - i;
					printf("%d\n", k);
					//stock = malloc()
					break;
				}
				//printf("%d : %c\n", i + 1, buf[i]);
				str[i] = buf[i];
				i++;
			}
		buf[ret] = '\0';
		//k = ft_check(buf);
		//ft_putstr("line :");
		//ft_putstr(ft_strndup(buf, k));
		//printf("nombre de caracteres lus:\n%d\n", ret);
		//printf("caracteres lus:\n%s\n", buf);
		//ft_putstr("ret: ");
		//ft_putnbr(ret);
		//ft_putstr("buf :");
		//ft_putstr(buf);
	}
	str[i+1] = '\0';
	ft_putstr(str);
	ft_putstr("**end**");
	line = NULL;
	return(**line);
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

int	main(int ac, char **av)
{
	int	fd;
	char**	line[250];

	av++;
	if(ac)
	{
		fd = open(*av, O_RDONLY);
		get_next_line(fd, *line);
	}
	return(1);
}