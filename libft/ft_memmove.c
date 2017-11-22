/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtennero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 16:13:08 by vtennero          #+#    #+#             */
/*   Updated: 2017/11/20 13:11:15 by vtennero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	if (len)
	{
		if (dst > src)
			i = len - 1;
		else
			i = 0;
		while (len-- > 0)
		{
			s1[i] = s2[i];
			if (dst > src)
				i--;
			else
				i++;
		}
	}
	return (s1);
}

int	main(void)
{
	char	a[6] = "salut";
	char	b[6] = "salut";

	printf("%s\n", ft_memmove(a+2, a, 4));
	printf("%s\n", memmove(b+2 , b, 4));
return (0);
}
