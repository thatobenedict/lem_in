/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_admin2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 12:40:04 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/28 09:33:22 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	duplicate_paths(int room1, int room2, t_lem *lem)
{
	if (lem->map->array[room1][room2] == 1)
		err_message(5);
}

void	loop(t_lem *lem)
{
	int i;
	int count;
	int first;
	int end;

	i = -1;
	count = 0;
	first = 0;
	end = lem->room->size - 2;
	while (++i <= end)
	{
		if (lem->map->array[end][i] == 1)
			count++;
	}
	if (count == 0)
		err_message(4);
	count = 0;
	while (--i >= -1)
	{
		if (lem->map->array[first][i] == 1)
			count++;
	}
	if (count == 0)
		err_message(4);
}
