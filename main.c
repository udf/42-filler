/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:51:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/09 20:03:59 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_map(t_map *map)
{
	size_t i;
	char **data;

	i = 0;
	data = (char**)map->data->data;
	while (i < map->h)
	{
		printf("%s\n", data[i]);
		i++;
	}
}

int	main(void)
{
	t_info		game_info;
	t_map		map;
	t_token		token;

	if (get_game_info(&game_info))
		return (1);
	map.data = vec_new(sizeof(char *), 0);
	token.data = vec_new(sizeof(char *), 0);
	while (1)
	{
		if (get_map(&game_info, &map))
			break ;
		print_map(&map);
	}
	vec_free(&map.data);
	vec_free(&token.data);
	return 0;
}