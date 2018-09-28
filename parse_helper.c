/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 09:53:49 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/28 09:54:07 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		room_stack(t_lem *lem)
{
	int i;

	i = 0;
	lem->room = new_room_arr((lem->room_size + 3));
	lem->room->array[0] = ft_strdup(lem->start);
	while (++i <= lem->room_size)
		lem->room->array[i] = ft_strdup(lem->hold[i - 1]);
	lem->room->array[lem->room->size - 2] = ft_strdup(lem->end);
	lem->room->array[lem->room->size - 1] = 0;
	lem->map = new_map(lem->room_size + 2);
	duplicate_rooms(lem);
}

void		relations_stack(t_lem *lem)
{
	int i;
	int j;

	i = lem->room_size;
	j = 0;
	lem->relations = new_room_arr(lem->relations_size + 1);
	while (j < lem->relations_size)
	{
		lem->relations->array[j] = ft_strdup(lem->hold[i]);
		j++;
		i++;
	}
	lem->relations->array[lem->relations_size] = 0;
}

void		pop_map(t_lem *lem)
{
	int j;
	int k;

	lem->map = new_map((lem->room_size + 2));
	j = -1;
	while (++j < (lem->room_size + 2))
	{
		k = -1;
		while (++k < (lem->room_size + 2))
			lem->map->array[j][k] = 0;
	}
	one_or_zero(lem);
}
