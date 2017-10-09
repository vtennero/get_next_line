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

NAME = a.out

FLAGS = -Wall -Werror -Wextra

#SRC = libft/srcs/ft_memcmp.c libft/srcs/ft_strclr.c libft/srcs/ft_strnequ.c libft/srcs/ft_atoi.c \
	  libft/srcs/ft_memcpy.c libft/srcs/ft_strcmp.c libft/srcs/ft_strnew.c libft/srcs/ft_bzero.c \
	  libft/srcs/ft_memdel.c libft/srcs/ft_strcpy.c libft/srcs/ft_strnstr.c libft/srcs/ft_isalnum.c \
	  libft/srcs/ft_memmove.c libft/srcs/ft_strdel.c libft/srcs/ft_strrchr.c libft/srcs/ft_isalpha.c \
	  libft/srcs/ft_memset.c libft/srcs/ft_strdup.c libft/srcs/ft_strsplit.c libft/srcs/ft_isascii.c \
	  libft/srcs/ft_putchar.c libft/srcs/ft_strequ.c libft/srcs/ft_isdigit.c \
	  libft/srcs/ft_putchar_fd.c libft/srcs/ft_striter.c libft/srcs/ft_isprint.c \
	  libft/srcs/ft_putendl.c libft/srcs/ft_striteri.c libft/srcs/ft_strstr.c libft/srcs/ft_itoa.c \
	  libft/srcs/ft_putendl_fd.c libft/srcs/ft_putnbr.c libft/srcs/ft_strlcat.c \
	  libft/srcs/ft_strtrim.c libft/srcs/ft_strjoin.c libft/srcs/ft_strsub.c \
	  libft/srcs/ft_putnbr_fd.c libft/srcs/ft_strlen.c libft/srcs/ft_strmap.c libft/srcs/ft_putstr.c \
	  libft/srcs/ft_putstr_fd.c libft/srcs/ft_strmapi.c libft/srcs/ft_tolower.c \
	  libft/srcs/ft_memalloc.c libft/srcs/ft_strncat.c libft/srcs/ft_toupper.c \
	  libft/srcs/ft_memccpy.c libft/srcs/ft_strcat.c libft/srcs/ft_strncmp.c libft/srcs/ft_memchr.c \
	  libft/srcs/ft_strchr.c libft/srcs/ft_strncpy.c

OBJ = ft_memcmp.o ft_strclr.o ft_strnequ.o ft_atoi.o ft_memcpy.o ft_strcmp.o \
	  ft_strnew.o ft_bzero.o ft_memdel.o ft_strcpy.o ft_strnstr.o \
	  ft_isalnum.o ft_memmove.o ft_strdel.o ft_strrchr.o ft_isalpha.o \
	  ft_memset.o ft_strdup.o ft_strsplit.o ft_isascii.o ft_putchar.o \
	  ft_strequ.o ft_isdigit.o ft_putchar_fd.o ft_striter.o \
	  ft_isprint.o ft_putendl.o ft_striteri.o ft_strstr.o ft_itoa.o \
	  ft_putendl_fd.o ft_strjoin.o ft_strsub.o  ft_putnbr.o \
	  ft_strlcat.o ft_strtrim.o ft_putnbr_fd.o ft_strlen.o \
	  ft_putstr.o ft_strmap.o ft_putstr_fd.o \
	  ft_strmapi.o ft_tolower.o ft_memalloc.o ft_strncat.o ft_toupper.o \
	  ft_memccpy.o ft_strcat.o ft_strncmp.o ft_memchr.o ft_strchr.o \
	  ft_strncpy.o

HEADER = libft/includes/

all:
	@ gcc $(FLAGS) -I $(HEADER) -c get_next_line.c
	#@ gcc $(FLAGS) -I $(HEADER) -c main.c
	#@ gcc $(FLAGS) $(SRC) -I$(HEADER) -c get_next_line.c
	#@ gcc $(FLAGS) $(SRC) -I$(HEADER) -c get_next_line.c
	#@ ar rc $(NAME) $(OBJ)
	@gcc -o test_gnl get_next_line.o -L libft/ -lft

clean:
	@ /bin/rm -f $(OBJ)

fclean: clean
	@ /bin/rm -f $(NAME)

re: fclean all
