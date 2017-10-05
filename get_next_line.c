#include "get_next_line.h"

int	get_next_line(int const fd, char ** line)
{
	int	ret;
	char	buf[BUF_SIZE +1];

	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		ft_putnbr(ret);
		ft_putstr(buf);
	}
}