/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 15:26:48 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/27 15:30:42 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strjoin_clr_free(char *a, char *b, int d)
{
	char	*tmp1;
	char	*tmp2;

	tmp1 = a;
	tmp2 = b;
	if (d == 0)
		free(tmp1);
	else if (d == 1)
		free(tmp2);
	else if (d == 2)
	{
		free(tmp1);
		free(tmp2);
	}
}

char		*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;
	size_t	i;

	if (!(s = (char *)malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b) + 1))))
		return (NULL);
	i = 0;
	while (a && *a)
		s[i++] = *a++;
	while (b && *b)
		s[i++] = *b++;
	s[i] = '\0';
	ft_strjoin_clr_free(a, b, d);
	return (s);
}
