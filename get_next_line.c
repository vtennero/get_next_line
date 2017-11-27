/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 19:19:36 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/27 12:45:56 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
static char	*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;
	size_t	i;

	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	i = 0;
	while (*a)
		s[i++] = *a++;
	while (*b)
		s[i++] = *b++;
	s[i] = '\0';
	if (d == 0)
		free(a);
	else if (d == 1)
		free(b);
	else if (d == 2)
	{
		free(a);
		free(b);
	}
	return (s);
}
*/

static int		ft_rank_backslash(char *str)
{
	int			i;

	i = -1;
	while (str[i] != '\n')
	{
		++i;
		if (str[i] == '\0')
			return (-1);
	}
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*str;
	static char	*tmp;
	int			n;

	n = -1;
	if (!line)
		return (-1);
	*line = 0;
	str = NULL;
	if (tmp)
	{
		if ((n = ft_rank_backslash(tmp)) >= 0)
		{
			*line = ft_strndup(tmp, n);
			tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
			return (1);
		}
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
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
