/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/12 20:21:44 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/13 12:59:32 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static size_t	can_place(t_info *info, t_map *map, t_token *token,
																t_point m_pos)
{
	t_point	t_pos;
	size_t	num_overlaps;
	char	map_tile;

	num_overlaps = 0;
	t_pos = make_point(-1, 0);
	while (map_iter((t_map *)token, &t_pos))
	{
		map_tile = map_get_tile(map, add_points(m_pos, t_pos));
		if (map_get_tile((t_map *)token, t_pos) == '*')
		{
			if (map_tile == info->them)
				return (0);
			if (map_tile == info->us)
				num_overlaps++;
			if (num_overlaps > 1)
				return (0);
		}
	}
	return (num_overlaps == 1);
}

int				next_move(t_info *info, t_map *map, t_token *token,
																t_point *m_pos)
{
	while (map_iter(map, m_pos))
	{
		if (m_pos->x + token->w > map->w || m_pos->y + token->h > map->h)
			continue ;
		if (can_place(info, map, token, *m_pos))
			return (1);
	}
	return (0);
}