/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:11:01 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/21 18:32:40 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		ft_initial(t_lem *lem)
{
	lem->gnl.line = 0;
}

//void		dupe_err(t_lem *lem)
//{
//}


int			ret_index(char *name, t_room *room)
{
	int i;

	i = 0;
	while (i <= room->size)
	{
		if (ft_strcmp(name, room->array[i]) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int			one_or_zero(int row, int col, t_lem *l)
{
	int i;

	i = -1;
	while (++i < (l->room_size + 2))
	{
		if (
				(ft_strnequ(l->room->array[row], l->relations->array[i], ft_strlen_n(l->relations->array[i], '-')) &&
				ft_strequ(l->room->array[col], ft_strrchr(l->relations->array[i], '-'))) ||
				((ft_strnequ(l->room->array[col], l->relations->array[i], ft_strlen_n(l->relations->array[i], '-')) &&
				ft_strequ(l->room->array[row],ft_strrchr(l->relations->array[i], '-'))))
			)
		   
			return (1);
	}
	return (0);
}
