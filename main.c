/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:51:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/12 21:19:35 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_map(const t_map *map)
{
	t_point p;

	p = make_point(-1, 0);
	while (map_iter(map, &p))
	{
		ft_putchar(map_get_tile(map, p));
		if ((p.x + 1) % map->w == 0)
			ft_putchar('\n');
	}
}

int		do_move(t_info *info, t_map *map, t_token *token)
{
	t_point p;

	p = make_point(-1, 0);
	while (next_move(info, map, token, &p))
	{
		printf("%zd %zd\n", p.x, p.y);
	}
	return 0;
}

int		main(void)
{
	t_info		game_info;
	t_map		map;
	t_token		token;

	if (get_game_info(&game_info))
		return (1);
	map.data = vec_new(1, 0);
	token.data = vec_new(1, 0);
	while (1)
	{
		if (get_map(&map))
			break ;
		//print_map(&map);
		if (get_token(&token))
			break ;
		//print_map((t_map *)&token);
		if (do_move(&game_info, &map, &token))
			break;
	}
	vec_free(&map.data);
	vec_free(&token.data);
	return (0);
}
