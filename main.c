/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:51:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/18 09:24:08 by mhoosen          ###   ########.fr       */
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

int		score(t_info *info, t_map *map, t_token *token, t_point move)
{
	t_point	p1;
	t_point	p2;
	t_point	iter;
	t_point rad;
	int		score;

	move = add_points(move, token->center);
	rad = make_point(token->w * 2, token->h * 2);
	p1 = map_clamp_point(map, sub_points(move, rad));
	p2 = map_clamp_point(map, add_points(move, rad));
	iter_points_begin(&iter, p1, p2);
	score = 0;
	while (1)
	{
		if (map_get_tile(map, iter) == info->us)
			score--;
		if (map_get_tile(map, iter) == info->them)
			score++;
		if (!iter_points_next(&iter, p1, p2))
			break ;
	}
	return (score);
}

int		do_move(t_info *info, t_map *map, t_token *token)
{
	t_point	this_move;
	int		this_score;
	t_point	best_move;
	int		best_score;

	this_move = make_point(-1, 0);
	best_move = make_point(0, 0);
	best_score = -999999;
	while (next_move(info, map, token, &this_move))
	{
		this_score = score(info, map, token, this_move);
		if (this_score >= best_score)
		{
			best_move = this_move;
			best_score = this_score;
		}
	}
	best_move = add_points(best_move, token->off);
	ft_putnbr(best_move.y);
	ft_putchar(' ');
	ft_putnbr(best_move.x);
	ft_putchar('\n');
	return (0);
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
	game_info.origin = make_point(-1, -1);
	while (1)
	{
		if (get_map(&game_info, &map))
			break ;
		if (get_token(&token))
			break ;
		if (do_move(&game_info, &map, &token))
			break ;
	}
	vec_free(&map.data);
	vec_free(&token.data);
	return (0);
}
