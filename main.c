/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 12:02:00 by vtennero          #+#    #+#             */
/*   Updated: 2017/12/06 11:28:02 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			//ft_putnbr(return_value);
			ft_putendl(line);
			i++;
			free(line);
		}
			//ft_putnbr(return_value);
		close(fd);
		free(line);
		//while (1)
		//	;
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
