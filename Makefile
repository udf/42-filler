# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 07:39:20 by mhoosen           #+#    #+#              #
#    Updated: 2018/07/06 16:22:16 by mhoosen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=main.c util.c game_info.c map.c
NAME=filler
CFLAGS=-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	gcc $(CFLAGS) -I libft/includes $(SRCS) -o $(NAME) -L libft/ -lft

clean:
	;

fclean: clean
	rm -f $(NAME)

re: fclean all
