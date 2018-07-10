/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:55:48 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/10 23:18:59 by anonymous        ###   ########.fr       */
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
** Reads the actual map data from stdin
** if successful, map->data->length should equal map->h
*/
static void	read_map(t_map *map)
{
	char	*line;
	char	*data;
	ssize_t	i;

	map->data->length = 0;
	map->data->type_size = (size_t)map->w;
	i = 0;
	while (i < map->h)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		if (ft_strlen(line) != (size_t)(map->w + 4))
		{
			free(line);
			break ;
		}
		// TODO: perhaps dont hardcode 3 char ruler width
		data = ft_strlower(ft_strsub(line, 4, (size_t)map->w));
		vec_append(map->data, data);
		free(line);
		i++;
	}
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