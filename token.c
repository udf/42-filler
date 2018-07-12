/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:13:14 by anonymous         #+#    #+#             */
/*   Updated: 2018/07/12 16:00:29 by mhoosen          ###   ########.fr       */
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

static void	trim_token(t_token *token)
{
	t_point	min;
	t_point	max;
	t_point	p;

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
	printf("min: %zd, %zd\n", min.x, min.y);
	printf("max: %zd, %zd\n", max.x, max.y);
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
