/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 16:36:24 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/27 16:42:32 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_eol_is_full(char *tmp, char **line)
{
	int		n;

	n = -1;
	if (tmp)
	{
		if ((n = ft_char_pos(tmp, '\n')) >= 0)
		{
			*line = ft_strndup(tmp, n);
			//tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
			return (1);
		}
	}
	return (0);
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
	if (ft_eol_is_full(tmp, line) == 1)
	{
		tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
		return (1);
	}
		/*if (tmp)
	  {
	  if ((n = ft_char_pos(tmp, '\n')) >= 0)
	  {
	 *line = ft_strndup(tmp, n);
	 tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
	 return (1);
	 }
	 }*/
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!str)
			//		{
			//			if (tmp)
			//			{
			str = ft_strjoin_clr(tmp, buf, 3);
		//			}
		//			else
		//				str = ft_strdup(buf);
		//		}
		else
			str = ft_strjoin(str, buf);
		n = -1;
		if ((n = ft_char_pos(str, '\n')) >= 0)
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
