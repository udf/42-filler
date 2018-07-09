/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 11:51:47 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/09 21:41:18 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_strvec(t_vec *v)
{
	size_t i;
	char **data;

	i = 0;
	data = (char**)v->data;
	while (i < v->length)
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
		print_strvec(map.data);
		if (get_token(&token))
			break ;
		print_strvec(token.data);
	}
	clear_ptr_vec(map.data);
	clear_ptr_vec(token.data);
	vec_free(&map.data);
	vec_free(&token.data);
	return 0;
}