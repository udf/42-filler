/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 11:19:31 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 12:00:12 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Reads the map data from stdin
** if successful, map->data->length should equal map->h
*/
void	read_map(t_map *map)
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