# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 07:39:20 by mhoosen           #+#    #+#              #
#    Updated: 2018/07/12 16:00:52 by mhoosen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=main.c util.c map_util.c game_info.c map.c token.c input.c
NAME=filler
CFLAGS=-Wall -Wextra -Werror -Wconversion

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	gcc $(CFLAGS) -I libft/includes $(SRCS) -o $(NAME) -L libft/ -lft

clean:
	;

fclean: clean
	rm -f $(NAME)

re: fclean all
