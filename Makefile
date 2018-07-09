# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/25 07:39:20 by mhoosen           #+#    #+#              #
#    Updated: 2018/07/09 21:29:08 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=main.c util.c game_info.c map.c token.c
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
