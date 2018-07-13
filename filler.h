/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:11:15 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/13 14:35:58 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "vec.h"

/*
** Your standard 2D point
*/
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

/*
** Information about the game
*/
typedef struct	s_info
{
	char		us;
	char		them;
	t_point		origin;
}				t_info;

/*
** Stores data about the map
** The actual map data is a vector of chars
** A description of how the data is stored can be found at get_tile
*/
typedef struct	s_map
{
	t_vec		*data;
	int			w;
	int			h;
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
	int			w;
	int			h;
	t_point		off;
	t_point		center;
}				t_token;

/*
**     __                _
**    / /   ____  ____ _(_)____
**   / /   / __ \/ __ `/ / ___/
**  / /___/ /_/ / /_/ / / /__
** /_____/\____/\__, /_/\___/
**             /____/
*/
int				next_move(t_info *info, t_map *map, t_token *token,
																t_point *m_pos);

/*
**     ____                  __
**    /  _/___  ____  __  __/ /_
**    / // __ \/ __ \/ / / / __/
**  _/ // / / / /_/ / /_/ / /_
** /___/_/ /_/ .___/\__,_/\__/
**          /_/
*/

/*
** Reads the map size line (PREFIX HEIGHT WIDTH:)
** If successful the map's w and h should both be > 0
*/
void			read_map_size(t_map *map, const char *prefix);

int				verify_map(t_map *map, const char *allowed, const char *req);

/*
** Reads the map data from stdin
** if successful, map->data->length should equal map->h
*/
void			read_map_data(t_map *map);

/*
** Reads the game information from stdin
** If an error occurs, returns 1 else 0
*/
int				get_game_info(t_info *info);

/*
** Reads an entire map from stdin and updates the map
** If an error occurs, returns 1 else 0
*/
int				get_map(t_info *info, t_map *map);

/*
** Reads an entire token from stdin and updates the token
** If an error occurs, returns 1 else 0
*/
int				get_token(t_token *token);

/*
**    __  ____  _ ___ __  _
**   / / / / /_(_) (_) /_(_)__  _____
**  / / / / __/ / / / __/ / _ \/ ___/
** / /_/ / /_/ / / / /_/ /  __(__  )
** \____/\__/_/_/_/\__/_/\___/____/
*/

/*
** Returns a [pointer to/character of] a tile at the specified point on a map
** returns NULL if the point is outside of the map
** This is needed because the data is stored as a vector of rows (chars)
** For example, the map:
** ..X
** .X.
** X..
** would be stored as "..X.X.X.." with a type_size of 3 bytes
*/
char			*map_get_tile_ptr(const t_map *map, const t_point p);
char			map_get_tile(const t_map *map, const t_point p);

/*
** Moves p to the next point in map
** Returns 1 if p is a valid point
*/
int				map_iter(const t_map *map, t_point *p);

/*
** Returns a clamped point so that it is inside the map
*/
t_point			map_clamp_point(const t_map *map, t_point p);

/*
** Constructs a t_point
*/
t_point			make_point(int x, int y);

/*
** Adds the x and y components of two t_points
*/
t_point			add_points(t_point a, t_point b);

/*
** Subtracts the x and y components of two t_points
*/
t_point			sub_points(t_point a, t_point b);

/*
** Begins iteration of a rectangle defined by two points
*/
void			iter_points_begin(t_point *p, t_point b1, t_point b2);

/*
** Advances to the next point in a rectangle defined by two points
** Returns 1 if the new point is in the rectangle
*/
int				iter_points_next(t_point *p, t_point b1, t_point b2);

/*
** Returns the Manhattan distance between two points
*/
int				point_dist(t_point a, t_point b);

/*
** Prints the specified string to stderr and returns 1
*/
int				print_error(char *str);

#endif
