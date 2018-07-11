/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:55:48 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 12:07:08 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Reads an entire map from stdin and updates the game info and map
** If an error occurs, returns 1 else 0
*/
int			get_map(t_map *map)
{
	char	*line;

	read_map_size(map, "Plateau ");
	if (map->w <= 0 || map->h <= 0)
		return (print_error("Failed to read map size\n"));
	if (get_next_line(0, &line) <= 0) // TODO: perhaps verify ruler length(/contents?)
		return (print_error("Failed to read map ruler\n"));
	free(line);
	read_map(map);
	if (map->data->length != (size_t)map->h)
	{
		map->data->length = 0;
		return (print_error("Failed to read map\n"));
	}
	return (0);
}