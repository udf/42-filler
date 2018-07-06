/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:11:15 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/06 16:33:21 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include "vec.h"
#include <stdio.h> //aaa

typedef struct	s_info
{
	char		us;
	char		them;
	size_t		map_w;
	size_t		map_h;
}				t_info;

typedef struct	s_map
{
	t_vec		*data;
	size_t		w;
	size_t		h;
}				t_map;

typedef struct	s_token
{
	t_vec		*data;
	size_t		w;
	size_t		h;
	size_t		center_x;
	size_t		center_y;
	ssize_t		x_off;
	ssize_t		y_off;
}				t_token;

/*
** Utilities
*/
void	clear_ptr_vec(t_vec *v);
int		print_error(char *str);

/*
** Input
*/
int		get_game_info(t_info *p_info);
int		get_map(t_info *info, t_map *map);

#endif