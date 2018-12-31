/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:55:48 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/13 14:34:05 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	set_origin(t_info *info, t_map *map)
{
	t_point p;

	p = make_point(-1, 0);
	while (map_iter(map, &p))
	{
		if (map_get_tile(map, p) == info->us)
		{
			info->origin = p;
			break ;
		}
	}
}

int			get_map(t_info *info, t_map *map)
{
	char	*line;

	read_map_size(map, "Plateau ");
	if (map->w <= 0 || map->h <= 0)
		return (print_error("Failed to read map size\n"));
	if (get_next_line(0, &line) <= 0)
		return (print_error("Failed to read map ruler\n"));
	free(line);
	read_map_data(map);
	if (map->data.length != (size_t)map->h)
	{
		map->data.length = 0;
		return (print_error("Failed to read map data\n"));
	}
	if (verify_map(map, ".ox", "ox"))
	{
		map->data.length = 0;
		return (print_error("Invalid map data\n"));
	}
	if (info->origin.x < 0 || info->origin.y < 0)
		set_origin(info, map);
	return (0);
}
