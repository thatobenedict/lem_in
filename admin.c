/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:11:01 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/27 12:54:27 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		ft_initial(t_lem *lem)
{
	lem->gnl.line = 0;
	lem->flag = 0;
	lem->i = 0;
	lem->hold_size = 0;
}

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

void		one_or_zero(t_lem *l)
{
	int i;
	char *room_char1;
	char *room_char2;
	int	room1_int;
	int	room2_int;

	i = -1;
	while (++i < (l->relations_size))
	{
		room_char1 = ft_strndup(l->relations->array[i],
				ft_strlen_n(l->relations->array[i], '-'));
		room_char2 = ft_strdup(l->relations->array[i] +
				ft_strlen_n(l->relations->array[i], '-') + 1);
		no_room(room_char1, room_char2, l);
		room1_int = ret_index(room_char1, l->room);
		room2_int = ret_index(room_char2, l->room);
		duplicate_paths(room1_int, room2_int, l);
		l->map->array[room1_int][room2_int] = 1;
		l->map->array[room2_int][room1_int] = 1;
		ft_strdel(&room_char1);
		ft_strdel(&room_char2);
	}
}
