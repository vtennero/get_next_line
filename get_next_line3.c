/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:19:36 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/24 16:37:26 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
   static void	ft_putnendl(char *str, int n)
   {
   while (n > 0)
   {
   write(1, &(*str), 1);
   str++;
   n--;
   }
   ft_putchar(10);
   }
   */
static int	ft_rank_backslash(char *str)
{
	int		i;

	i = 0;
	//ft_putnendl(str, ret);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			//ft_putnbr(i);
			return (i);
		}
		++i;
	}
	return (-1);
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
   */
static int	ft_parse(char **line, char *eol)
{
	int			n;

	n = 0;
	if (eol != 0)
	{
		*line = ft_strjoin(eol, *line);
	}
	n = ft_rank_backslash(*line);
	if (n >= 0)
	{
		eol = ft_strdup(ft_strchr(*line + 1, 10));
		*line = ft_strndup(*line, n);
		ft_putendl("eol :");
		ft_putendl(eol);
		return (1);
	}
	else
	{
		return (0);
	}
}

int	get_next_line(int const fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;
	static char	*eol;
	int		n = 0;

	if (!line)
		return (-1);
	*line = 0;
	if (eol != 0)
	{
		ft_putendl("BUFFER NOT EMPTY");
		n = ft_rank_backslash(eol);
		*line = ft_strndup(eol, n);
		eol = ft_strdup(ft_strchr(eol + 1, 10));
		return(1);
	}
	else
	{
		while ((ret = read(fd, buf, BUFF_SIZE)) != 0)
		{
			buf[ret] = '\0';
			tmp = *line;
			if (tmp)
				*line = ft_strjoin(*line, buf);
			else
				*line = ft_strdup(buf);
			if (ft_parse(line, eol) == 1)
				return (1);
			free (tmp);
		}
		return (0);
	}
	return (-1);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		return_value;

	return_value = 47;
	if (ac)
	{
		fd = open(av[1], O_RDONLY);
		while ((return_value = get_next_line(fd, &line)) == 1)
		{
			ft_putstr("line: ");
			//ft_putnbr(return_value);
			ft_putendl(line);
		}
		//if ((return_value = get_next_line(fd, &line)) == 0)
		//{
		//	ft_putstr("final line: ");
		//ft_putnbr(return_value);
		//	ft_putendl(line);
		//}
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
