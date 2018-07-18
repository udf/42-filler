/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:49:12 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/18 21:32:49 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		point_dist(t_point a, t_point b)
{
	int xd;
	int yd;
	xd = a.x - b.x;
	yd = a.y - b.y;
	return (xd*xd + yd*yd);
}

int		print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}
