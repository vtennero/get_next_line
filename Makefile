# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 15:16:05 by vtennero          #+#    #+#              #
#    Updated: 2017/07/22 12:28:27 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

FLAGS = -Wall -Werror -Wextra

SRC = get_next_line.c get_next_line.h

all:
	@ gcc $(FLAGS) -o main $(SRC) -I$(LIB)

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f a.out

re: fclean all
