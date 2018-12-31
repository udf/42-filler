/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:13:14 by anonymous         #+#    #+#             */
/*   Updated: 2018/07/18 09:25:58 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	shift_rows(t_token *token, int shift, size_t new_w)
{
	int		y;
	char	*dst;
	char	*src;

	y = 0;
	while (y < token->h)
	{
		dst = map_get_tile_ptr((t_map *)token, (t_point){0, y});
		src = map_get_tile_ptr((t_map *)token, (t_point){shift, y});
		ft_memmove((void *)dst, (void *)src, new_w);
		y++;
	}
}

static void	trim_token(t_token *token)
{
	t_point	min;
	t_point	max;
	t_point	p;
	int		new_w;

	min = make_point(token->w, token->h);
	max = make_point(0, 0);
	p = make_point(-1, 0);
	while (map_iter((t_map *)token, &p))
	{
		if (map_get_tile((t_map *)token, p) == '*')
		{
			min = make_point(MIN(min.x, p.x), MIN(min.y, p.y));
			max = make_point(MAX(max.x, p.x), MAX(max.y, p.y));
		}
	}
	token->h = max.y - min.y + 1;
	new_w = max.x - min.x + 1;
	vec_del_n(&token->data, (size_t)min.y);
	shift_rows(token, min.x, (size_t)new_w);
	token->w = new_w;
	token->off = make_point(-min.x, -min.y);
}

static void	compute_center(t_token *token)
{
	t_point	sum;
	t_point	p;
	int		n_tiles;

	sum = make_point(0, 0);
	p = make_point(-1, 0);
	n_tiles = 0;
	while (map_iter((t_map *)token, &p))
	{
		if (map_get_tile((t_map *)token, p) == '*')
		{
			sum = add_points(sum, p);
			n_tiles++;
		}
	}
	token->center = make_point(sum.x / n_tiles, sum.y / n_tiles);
}

int			get_token(t_token *token)
{
	read_map_size((t_map *)token, "Piece ");
	if (token->w <= 0 || token->h <= 0)
		return (print_error("Failed to read token size\n"));
	read_map_data((t_map *)token);
	if (token->data.length != (size_t)token->h)
	{
		token->data.length = 0;
		return (print_error("Failed to read valid token data\n"));
	}
	if (verify_map((t_map *)token, ".*", "*"))
	{
		token->data.length = 0;
		return (print_error("Invalid token data\n"));
	}
	trim_token(token);
	compute_center(token);
	return (0);
}
