#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymushet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/03 13:46:12 by ymushet           #+#    #+#              #
#    Updated: 2017/03/03 16:59:28 by ymushet          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

SRC = func.c ft_printf.c modifier.c parsing.c presicion.c print.c printtext.c unsigned.c width.c undefined.c signed.c wchar.c

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	ar rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

%.o: %.c
	gcc $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all