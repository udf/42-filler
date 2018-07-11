/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:51:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 16:52:06 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_mapvec(t_vec *v)
{
	size_t	i;
	char	*data;

	i = 0;
	data = (char*)v->data;
	while (i < v->length)
	{
		write(1, data + i * v->type_size, v->type_size);
		write(1, "\n", 1);
		i++;
	}
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
		print_mapvec(map.data);
		if (get_token(&token))
			break ;
		print_mapvec(token.data);
	}
	vec_free(&map.data);
	vec_free(&token.data);
	return (0);
}
