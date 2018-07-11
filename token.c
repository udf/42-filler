/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:13:14 by anonymous         #+#    #+#             */
/*   Updated: 2018/07/11 12:06:54 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	validate_token(t_token *token)
{
	t_point i;
	char	tile;

	i.y = 0;
	while (i.y < token->h)
	{
		i.x = 0;
		while (i.x < token->w)
		{
			tile = get_tile((t_map *)token, i);
			if (tile != '*' && tile != '.')
				return (1);
			i.x++;
		}
		i.y++;
	}
	return (0);
}

static void	trim_token(t_token *token)
{
	t_point	min;
	t_point	max;
	t_point	i;
	char	tile;

	min.x = token->w;
	min.y = token->h;
	max.x = 0;
	max.y = 0;
	i.y = 0;
	while (i.y < token->h)
	{
		i.x = 0;
		while (i.x < token->w)
		{
			tile = get_tile((t_map *)token, i);
			if (tile == '*')
			{
				min.x = MIN(min.x, i.x);
				min.y = MIN(min.y, i.y);
				max.x = MAX(max.x, i.x);
				max.y = MAX(max.y, i.y);
			}
			i.x++;
		}
		i.y++;
	}

	printf("min: %zd, %zd\n", min.x, min.y);
	printf("max: %zd, %zd\n", max.x, max.y);
}

/*
** Reads an entire token from stdin and updates the token
** If an error occurs, returns 1 else 0
*/
int			get_token(t_token *token)
{
	read_map_size((t_map *)token, "Piece ");
	if (token->w <= 0 || token->h <= 0)
		return (print_error("Failed to read token size\n"));
	read_map((t_map *)token);
	if (token->data->length != (size_t)token->h || validate_token(token))
	{
		token->data->length = 0;
		return (print_error("Failed to read valid token data\n"));
	}
	trim_token(token);
	return (0);
}