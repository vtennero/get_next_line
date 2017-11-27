/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:24 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/27 20:13:29 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_eol_is_full(char *tmp, char **line)
{
	int		n;
	char	*str;

	str = *line;
	n = -1;
	if (tmp)
	{
		if ((n = ft_char_pos(tmp, '\n')) >= 0)
		{
			*line = ft_strndup(tmp, n);
			free(str);
			return (1);
		}
	}
	return (0);
}

/*
static int		ft_read_line(char *t, char **line, int const fd)
{
	int		n;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*str;

	str = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = (!str) ? ft_strjoin_clr(t, buf, 3) : ft_strjoin_clr(str, buf, 0);
		if ((n = ft_char_pos(str, '\n')) >= 0)
		{
			*line = ft_strndup(str, n);
			t = ft_strdup(ft_strchr(str, '\n') + 1);
			return (1);
		}
		else
			*line = str;
	}
	if (ret == 0)
		return (*line == NULL) ? 0 : 1;
	else
		return (-1);
}
*/

int				get_next_line(int const fd, char **line)
{
	static char	*t;
	int			n;
	char		buf[BUFF_SIZE + 1];
	int			ret;
	char		*str;

	if (!line)
		return (-1);
	*line = NULL;
	str = NULL;
	if (ft_eol_is_full(t, line) == 1)
	{
		t = ft_strdup(ft_strchr(t, '\n') + 1);
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str = (!str) ? ft_strjoin_clr(t, buf, 3) : ft_strjoin_clr(str, buf, 0);
		if ((n = ft_char_pos(str, '\n')) >= 0)
		{
			*line = ft_strndup(str, n);
			t = ft_strdup(ft_strchr(str, '\n') + 1);
			return (1);
		}
		*line = str;
	}
	if (ret == 0)
		return (*line == NULL) ? 0 : 1;
	return (-1);
}
