/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhoosen <mhoosen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:49:12 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/06 16:03:50 by mhoosen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_ptr_vec(t_vec *v)
{
	size_t	i;
	void	**data;

	if (!v)
		return ;
	i = 0;
	data = (void **)v->data;
	while (i < v->length)
	{
		free(data[i]);
		i++;
	}
	v->length = 0;
}

int		print_error(char *str)
{
	ft_putstr_fd(str, 2);
	return (1);
}
