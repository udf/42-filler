/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 11:06:28 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/13 14:34:18 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point	make_point(int x, int y)
{
	return (t_point){x, y};
}

t_point	add_points(t_point a, t_point b)
{
	return (t_point){a.x + b.x, a.y + b.y};
}

t_point	sub_points(t_point a, t_point b)
{
	return (t_point){a.x - b.x, a.y - b.y};
}

void	iter_points_begin(t_point *p, t_point b1, t_point b2)
{
	*p = make_point(MIN(b1.x, b2.x), MIN(b1.y, b2.y));
}

int		iter_points_next(t_point *p, t_point b1, t_point b2)
{
	t_point min;
	t_point max;

	min = make_point(MIN(b1.x, b2.x), MIN(b1.y, b2.y));
	max = make_point(MAX(b1.x, b2.x), MAX(b1.y, b2.y));
	p->x++;
	if (p->x > max.x)
	{
		p->x = min.x;
		p->y++;
	}
	return (p->y <= max.y);
}
