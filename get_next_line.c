/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:19:36 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/24 17:26:23 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//# define BUFF_SIZE 4

static int	ft_rank_backslash(char *str)
{
	int		i;

	i = -1;
	while (str[i] != '\n')
	{
		++i;
		if (str[i] == '\0')
			return (-1);
	}
	return (i);
}
/*
static char	*ft_strdupn(char *str, int n)
{
	int	i;
	char	*t;
	int		l;

	l = ft_strlen(str) - n - 1;
	t = (char *)malloc(sizeof(*t) * l + 1);
	i = 0;
	if (!t)
		return (NULL);
	while (i < l)
	{
		t[i] = str[n + 1 + i];
		i++;
	}
	t[i] = '\0';
	return (t);
}


int	*ft_parse(char *tmp, char **line)
{
	int		n;

	n = -1;
	//soit elle contient un \n => return(*line tronquee jusquau \n)
	if ((n = ft_rank_backslash(tmp)) >= 0)
	{
		*line = ft_strndup(tmp, n);
		tmp = ft_strdup(ft_strchr(tmp, '\n') +1);
		return (1);
	}
	return (0);
	//soit elle n'en contient pas => return(tout qui sera join avec la suite lue)
}
*/
int	get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*str;
	static char	*tmp;
	int		n = -1;

	*line = 0;
	str = NULL;
	if (tmp)
	{
	if ((n = ft_rank_backslash(tmp)) >= 0)
	{
		*line = ft_strndup(tmp, n);
		tmp = ft_strdup(ft_strchr(tmp, '\n') +1);
		return (1);
	}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		//ft_putnbr(ret);
		//ft_putendl(buf);
		buf[ret] = '\0';
		if (!str)
		{
			if (tmp)
			{
				str = ft_strjoin(tmp, buf);
			}
				else
				str = ft_strdup(buf);
		}
		else
			str = ft_strjoin(str, buf);
		n = -1;
		if ((n = ft_rank_backslash(str)) >= 0)
		{
			*line = ft_strndup(str, n);
			tmp = ft_strdup(ft_strchr(str, '\n') + 1);
			return (1);
		}
		else
			*line = str;
	}
	if (ret == 0)
	{
		if (*line == 0)
			return (0);
		return (1);
	}
	else
		return (-1);
}
/*
int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		return_value;
	int		i;

	i = 1;
	if (ac)
	{
		fd = open(av[1], O_RDONLY);
		while ((return_value = get_next_line(fd, &line)) == 1)
		{
			ft_putstr("line ");
			ft_putnbr(i);
			ft_putstr(" : ");
			ft_putnbr(return_value);
			ft_putendl(line);
			i++;
		}
		close(fd);
	}
	return (0);
}

   char    *line;
   int     r;
   int     i;

   line = NULL;
   i = 0;
   while ((r = get_next_line(0, &line)) > 0)
   printf("%i: %s\n", ++i, line);
   return (r);*/
