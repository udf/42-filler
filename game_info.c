/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:28:07 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/06 16:29:59 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void read_player(char *line, t_info *p_info)
{
	int		player_num;

	if (!ft_strnequ(line, "$$$ exec p", 10))
		return ;
	if (ft_strlen(line) < 11)
		return ;
	player_num = ft_atoi(line + 10);
	if (player_num == 1)
	{
		p_info->us = 'o';
		p_info->them = 'x';
	}
	else if (player_num == 2)
	{
		p_info->us = 'x';
		p_info->them = 'o';
	}
}

int	get_game_info(t_info *p_info)
{
	char	*line;

	if (get_next_line(0, &line) < 0)
		return (print_error("Failed to read player info line\n"));
	ft_bzero(p_info, sizeof(t_info));
	read_player(line, p_info);
	free(line);
	if (!p_info->us)
		return (print_error("Failed to read player\n"));
	return (0);
}