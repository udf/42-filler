/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:51:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/18 17:12:15 by mhoosen          ###   ########.fr       */
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

int		score(t_info *info, t_map *map, t_token *token, t_point p_move)
{
	int		score_enemy;
	int		score_self;
	p_move = add_points(p_move, token->center);
	score_enemy = dist_sum(map, p_move, info->them);
	score_self = dist_sum(map, p_move, info->us);
	return (score_self*score_self - score_enemy);
}

int		do_move(t_info *info, t_map *map, t_token *token)
{
	t_point	this_move;
	int		this_score;
	t_point	best_move;
	int		best_score;

	this_move = make_point(-1, 0);
	best_move = make_point(0, 0);
	best_score = -99999999;
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
