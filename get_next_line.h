#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUF_SIZE 5

#include <unistd.h>
//#include "libft/libft.a"

int	get_next_line(int const fd, char ** line);
int	ft_check(char *str);
char	*ft_strndup(const char *s1, int n);

#endif