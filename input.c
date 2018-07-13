/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:19:31 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/13 11:49:04 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	parse_map_size(char *line, t_map *map, const char *prefix)
{
	if (!ft_strnequ(line, prefix, ft_strlen(prefix)))
		return ;
	line = ft_strchr(line, ' ');
	if (!line)
		return ;
	map->h = ft_atoi(line);
	line = ft_strchr(line + 1, ' ');
	if (line)
		map->w = ft_atoi(line);
}

void		read_map_size(t_map *map, const char *prefix)
{
	char *line;

	map->w = 0;
	map->h = 0;
	if (get_next_line(0, &line) <= 0)
		return ;
	parse_map_size(line, map, prefix);
	free(line);
}

void		read_map_data(t_map *map)
{
	char	*line;
	char	*data;
	int		i;

	map->data->length = 0;
	map->data->type_size = (size_t)map->w;
	i = 0;
	while (i < map->h)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		data = ft_strchr(line, ' ');
		data = data ? data + 1 : line;
		if (ft_strlen(data) != (size_t)map->w)
		{
			free(line);
			break ;
		}
		data = ft_strlower(ft_strdup(data));
		vec_append(map->data, data);
		free(line);
		i++;
	}
}
