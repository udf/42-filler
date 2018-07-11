/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:28:07 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/11 15:38:06 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	read_player(char *line, t_info *info)
{
	int		player_num;

	if (!ft_strnequ(line, "$$$ exec p", 10))
		return ;
	if (ft_strlen(line) < 11)
		return ;
	player_num = ft_atoi(line + 10);
	if (player_num == 1)
	{
		info->us = 'o';
		info->them = 'x';
	}
	else if (player_num == 2)
	{
		info->us = 'x';
		info->them = 'o';
	}
}

int			get_game_info(t_info *info)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (print_error("Failed to read player info line\n"));
	ft_bzero(info, sizeof(t_info));
	read_player(line, info);
	free(line);
	if (!info->us)
		return (print_error("Failed to read player\n"));
	return (0);
}
