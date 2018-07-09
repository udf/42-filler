/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 21:13:14 by anonymous         #+#    #+#             */
/*   Updated: 2018/07/09 22:22:03 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Reads the token size line (Piece HEIGHT WIDTH:)
** If successful the token's w and h should both be > 0
*/
static void	get_token_size(char *line, t_token *token)
{
	token->w = 0;
	token->h = 0;
	if (!ft_strnequ(line, "Piece ", 6))
		return ;
	line = ft_strchr(line, ' ');
	if (line)
	{
		token->h = ft_atoi(line);
		line++;
	}
	line = ft_strchr(line, ' ');
	if (line)
		token->w = ft_atoi(line);
	return ;
}

/*
** Reads the actual token data from stdin
** if successful, token->data->length should equal token->h
*/
static void	read_token(t_token *token)
{
	char	*line;
	char	*data;
	ssize_t	i;

	i = 0;
	while (i < token->h)
	{
		if (get_next_line(0, &line) <= 0)
			break ;
		if (ft_strlen(line) != (size_t)token->w)
		{
			free(line);
			break ;
		}
		data = ft_strlower(ft_strdup(line));
		vec_append(token->data, &data);
		free(line);
		i++;
	}
}

/*
** Reads an entire token from stdin and updates the token
** If an error occurs, returns 1 else 0
*/
int			get_token(t_token *token)
{
	char	*line;

	clear_ptr_vec(token->data);
	if (get_next_line(0, &line) <= 0)
		return (print_error("Failed to read token info line\n"));
	get_token_size(line, token);
	free(line);
	if (token->w <= 0 || token->h <= 0)
		return (print_error("Invalid token size\n"));
	read_token(token);
	if (token->data->length != (size_t)token->h)
	{
		clear_ptr_vec(token->data);
		return (print_error("Failed to read token data\n"));
	}
	return (0);
}