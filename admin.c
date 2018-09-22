/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   admin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 09:11:01 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/22 12:17:07 by tbenedic         ###   ########.fr       */
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

int			one_or_zero(t_lem *l)//(int row, int col, t_lem *l)
{
	int i;
	int ret;
	char *room_char1;
	char *room_char2;
	int	room1_int;
	int	room2_int;

	i = -1;
	ret = 0;
	while (++i < (l->relations_size))
	{
		room_char1 = ft_strndup(l->relations->array[i], ft_strlen_n(l->relations->array[i], '-'));
		room_char2 = ft_strdup(l->relations->array[i] + ft_strlen_n(l->relations->array[i], '-') + 1);
		room1_int = ret_index(room_char1, l->room);
		room2_int = ret_index(room_char2, l->room);
		l->map->array[room1_int][room2_int] = 1;
		l->map->array[room2_int][room1_int] = 1;
	
	
	
		ft_putstr(l->relations->array[i]);
		ft_putstr("\t");
//		ft_putstr(room1);
		ft_putnbr(room1_int);
		ft_putstr("\t");
//		ft_putstr(room2);
		ft_putnbr(room2_int);
		ft_putstr("\n");
//		if ((ft_strcmp(l->room->array[row], room1) == 0 && ft_strcmp(l->room->array[col], room2) == 0))
//			ret = 1;
//		if ((ft_strcmp(l->room->array[col], room1) == 0 && ft_strcmp(l->room->array[row], room2) == 0))
//			ret = 1;
	}
	free(room_char1);
	free(room_char2);
	return (ret);
}
