/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:11:15 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/10 18:55:45 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "vec.h"
#include <stdio.h> //aaa

/*
** Your standard 2D point
*/
typedef struct	s_point
{
	ssize_t		x;
	ssize_t		y;
}				t_point;

/*
** Information about the game
*/
typedef struct	s_info
{
	char		us;
	char		them;
	ssize_t		map_w;
	ssize_t		map_h;
}				t_info;

/*
** Stores data about the map
** The actual map data is a vector of char pointers
*/
typedef struct	s_map
{
	t_vec		*data;
	ssize_t		w;
	ssize_t		h;
}				t_map;

/*
** Stores data about the token
** The actual token data is a vector of char pointers
** The width and height are the trimmed dimensions
** The offsets are the left and top trim amount (used when printing the move)
*/
typedef struct	s_token
{
	t_vec		*data;
	ssize_t		w;
	ssize_t		h;
	t_point		off;
}				t_token;

/*
** Utilities
*/
void	clear_ptr_vec(t_vec *v);
int		print_error(char *str);

/*
** Input
*/
int		get_game_info(t_info *p_info);
int		get_map(t_info *info, t_map *map);
int		get_token(t_token *token);

#endif