/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:55:48 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/06 16:57:23 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_map_size(char *line, t_info *info, t_map *map)
{
	map->w = 0;
	map->h = 0;

	if (!ft_strnequ(line, "Plateau ", 8))
		return ;
	line = ft_strchr(line, ' ') + 1;
	if (line)
		map->h = ft_atoi(line);
	line = ft_strchr(line, ' ') + 1;
	if (line)
		map->w = ft_atoi(line);
	if (info->map_w == 0 || info->map_h == 0)
	{
		info->map_w = map->w;
		info->map_h = map->h;
	}
	return ;
}

static void	read_map(t_map *map)
{
	char	*line;
	char	*data;
	size_t	i;

	i = 0;
	while (i < map->h)
	{
		if (get_next_line(0, &line) < 0)
			break ;
		if (ft_strlen(line) != map->w + 4)
		{
			free(line);
			break ;
		}
		data = ft_strlower(ft_strsub(line, 4, map->w));
		vec_append(map->data, &data);
		free(line);
		i++;
	}
}

int			get_map(t_info *info, t_map *map)
{
	char	*line;

	clear_ptr_vec(map->data);
	if (get_next_line(0, &line) < 0)
		return (print_error("Failed to read map info line\n"));
	get_map_size(line, info, map);
	free(line);
	if (info->map_w == 0 || info->map_h == 0 || map->w == 0 || map->h == 0)
		return (print_error("Failed to read map size\n"));
	if (map->w != info->map_w || map->h != info->map_h)
		return (print_error("wrong map size\n"));
	if (get_next_line(0, &line) < 0)
		return (print_error("Failed to read map ruler\n"));
	free(line);
	read_map(map);
	if (map->data->length != map->h)
	{
		clear_ptr_vec(map->data);
		return (print_error("Failed to read map\n"));
	}
	return (0);
}