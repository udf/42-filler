/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:55:48 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 11:54:47 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Reads the map size line (Plateau HEIGHT WIDTH:)
** Also sets the game info's dimensions if they are unset
** If successful the map's w and h should both be > 0
*/
static void	get_map_size(char *line, t_map *map)
{
	map->w = 0;
	map->h = 0;
	if (!ft_strnequ(line, "Plateau ", 8))
		return ;
	line = ft_strchr(line, ' ');
	if (line)
	{
		map->h = ft_atoi(line);
		line++;
	}
	line = ft_strchr(line, ' ');
	if (line)
		map->w = ft_atoi(line);
	return ;
}

/*
** Reads an entire map from stdin and updates the game info and map
** If an error occurs, returns 1 else 0
*/
int			get_map(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (print_error("Failed to read map info line\n"));
	get_map_size(line, map);
	free(line);
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