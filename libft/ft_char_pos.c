/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:20:12 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/27 15:23:04 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_char_pos(char *str, char c)
{
	int			i;

	i = -1;
	while (str[i] != c)
	{
		++i;
		if (str[i] == '\0')
			return (-1);
	}
	return (i);
}
