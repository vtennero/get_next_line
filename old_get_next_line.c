/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:24 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/28 11:26:43 by vtennero         ###   ########.fr       */
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

static char		*ft_read_line(char *t, char **line, int const fd, int *ret)
{
	int			n;
	char		buf[BUFF_SIZE + 1];
	char		*str;

	str = NULL;
	while ((*ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[*ret] = '\0';
		str = (!str) ? ft_strjoin_clr(t, buf, 3) : ft_strjoin_clr(str, buf, 0);
		if ((n = ft_char_pos(str, '\n')) >= 0)
		{
			*line = ft_strndup(str, n);
			t = ft_strdup(ft_strchr(str, '\n') + 1);
			return (t);
		}
		else
			*line = str;
	}
	return (t);
}

int				get_next_line(int const fd, char **line)
{
	static char	*t;
	char		*tmp;
	int			ret;

	if (!line || fd < 0)
		return (-1);
	*line = NULL;
	tmp = NULL;
	if (ft_eol_is_full(t, line) == 1)
	{
		t = ft_strdup(ft_strchr(t, '\n') + 1);
		return (1);
	}
	tmp = ft_read_line(t, line, fd, &ret);
	if (ft_strcmp(t, tmp) != 0)
	{
		t = tmp;
		return (1);
	}
	if (ret == -1)
		return (-1);
	return (*line == NULL) ? 0 : 1;
}
