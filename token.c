/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:13:14 by anonymous         #+#    #+#             */
/*   Updated: 2018/07/12 21:28:55 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_token(t_token *token)
{
	t_point	p;
	char	tile;

	p = make_point(-1, 0);
	while (map_iter((t_map *)token, &p))
	{
		tile = map_get_tile((t_map *)token, p);
		if (tile != '*' && tile != '.')
			return (1);
	}
	return (0);
}

static void	shift_rows(t_token *token, ssize_t shift, size_t new_w)
{
	ssize_t	y;
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
	ssize_t	new_w;

	min = make_point(token->w, token->h);
	max = make_point(0, 0);
	p = make_point(-1, 0);
	while (map_iter((t_map *)token, &p))
	{
		if (map_get_tile((t_map *)token, p) == '*')
		{
			min.x = MIN(min.x, p.x);
			min.y = MIN(min.y, p.y);
			max.x = MAX(max.x, p.x);
			max.y = MAX(max.y, p.y);
		}
	}
	token->h = max.y - min.y + 1;
	new_w = max.x - min.x + 1;
	vec_del_n(token->data, (size_t)min.y);
	shift_rows(token, min.x, (size_t)new_w);
	token->w = new_w;
	token->off = make_point(-min.x, -min.y);
}

int			get_token(t_token *token)
{
	read_map_size((t_map *)token, "Piece ");
	if (token->w <= 0 || token->h <= 0)
		return (print_error("Failed to read token size\n"));
	read_map_data((t_map *)token);
	if (token->data->length != (size_t)token->h || validate_token(token))
	{
		token->data->length = 0;
		return (print_error("Failed to read valid token data\n"));
	}
	trim_token(token);
	return (0);
}
