/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 12:49:12 by mhoosen           #+#    #+#             */
/*   Updated: 2018/07/09 21:42:57 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** Interprets a vector's data as an array of pointers and frees each one
** After running this, the vector can safely be freed with vec_free
*/
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
