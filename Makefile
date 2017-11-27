# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vtennero <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/17 15:16:05 by vtennero          #+#    #+#              #
#    Updated: 2017/11/27 12:11:30 by vtennero         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_gnl

FLAGS = -Wall -Werror -Wextra
#FLAGS = -Wall -Wno-empty-body -Wno-unused -Wextra

LIBFT_DIR = libft
LIBFT_NAME = libft.a

LIBFT = $(patsubst %, $(LIBFT_DIR)/%,$(LIBFT_NAME))

OBJ = get_next_line.o main.o

SRC = get_next_line.c main.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME) : $(LIBFT)
	@ gcc $(FLAGS) -c $(SRC) get_next_line.h
	@ gcc $(FLAGS) -o $(NAME) $(OBJ) -L $(LIBFT_DIR) -lft

$(LIBFT):
	@ make -C $(LIBFT_DIR)

clean:
	@ /bin/rm -f $(OBJ)
	@ make clean -C $(LIBFT_DIR)

fclean: clean
	@ /bin/rm -f $(NAME)
	@ make fclean -C $(LIBFT_DIR)

re: fclean all
