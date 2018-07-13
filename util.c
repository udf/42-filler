/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:49:12 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/13 10:31:32 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	make_point(int x, int y)
{
	return (t_point){x, y};
}

t_point	add_points(t_point *a, t_point *b)
{
	return (t_point){a->x + b->x, a->y + b->y};
}

int		print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}
