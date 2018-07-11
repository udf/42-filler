/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:49:12 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 13:06:54 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Returns the pointer to a tile at the specified point on a map
** returns NULL if the point is outside of the map
** This is needed because the data is stored as a vector of rows (chars)
** For example, the map:
** ..X
** .X.
** X..
** would be stored as "..X.X.X.." with a type_size of 3 bytes
*/
char	*get_tile_ptr(const t_map *map, const t_point p)
{
	char *data;

	if (p.x < 0 || p.y < 0 || p.x >= map->w || p.y >= map->h)
		return (NULL);
	data = (char *)map->data->data;
	return (&data[p.y * map->h + p.x]);
}

char	get_tile(const t_map *map, const t_point p)
{
	char *tile;

	tile = get_tile_ptr(map, p);
	return (tile ? *tile : '\0');
}

t_point	make_point(ssize_t x, ssize_t y)
{
	t_point p;

	p.x = x;
	p.y = y;
	return (p);
}

/*
** Moves p to the next point in map
** Returns 1 if p is a valid point
*/
int		map_iter(const t_map *map, t_point *p)
{
	p->x++;
	if (p->x >= map->w)
	{
		p->x = 0;
		p->y++;
	}
	return (p->y < map->h);
}

int		print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}
