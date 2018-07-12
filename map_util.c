/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 15:58:37 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/12 16:02:00 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*map_get_tile_ptr(const t_map *map, const t_point p)
{
	char *data;

	if (p.x < 0 || p.y < 0 || p.x >= map->w || p.y >= map->h)
		return (NULL);
	data = (char *)map->data->data;
	return (&data[(size_t)p.y * map->data->type_size + (size_t)p.x]);
}

char	map_get_tile(const t_map *map, const t_point p)
{
	char *tile;

	tile = map_get_tile_ptr(map, p);
	return (tile ? *tile : '\0');
}

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
