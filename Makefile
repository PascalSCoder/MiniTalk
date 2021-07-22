# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: pspijkst <pspijkst@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/06/08 21:02:55 by pspijkst      #+#    #+#                  #
#    Updated: 2021/07/22 21:33:47 by pspijkst      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	=	server
NAME2	=	client
SRC		=	shared/ft_atoi_strict.c shared/ft_itoa.c\
			shared/bit_tools.c shared/writes.c shared/ft_realloc_double.c
CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address

all: $(NAME) $(NAME2)

$(NAME2): $(SRC) client.c shared/minitalk.h
	gcc client.c $(SRC) -o client $(CFLAGS)

$(NAME): $(SRC) server.c shared/minitalk.h
	gcc server.c $(SRC) -o server $(CFLAGS)

clean:
	rm -f server client

fclean: clean

re: fclean all

.PHONY: all clean fclean re
