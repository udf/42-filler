/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:11:15 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 11:55:20 by mhoosen          ###   ########.fr       */
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
}				t_info;

/*
** Stores data about the map
** The actual map data is a vector of chars
** A description of how the data is stored can be found at get_tile
*/
typedef struct	s_map
{
	t_vec		*data;
	ssize_t		w;
	ssize_t		h;
}				t_map;

/*
** Stores data about the token
** Pretty much the same as t_map with an offset
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
char	*get_tile_ptr(const t_map *map, const t_point p);
char	get_tile(const t_map *map, const t_point p);
int		print_error(char *str);

/*
** Input
*/
void	read_map(t_map *map);

int		get_game_info(t_info *p_info);
int		get_map(t_map *map);
int		get_token(t_token *token);

#endif