/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:31:46 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/22 15:53:54 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		who_min(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->array[0];
	while (i <= array->top)
	{
		if (j > array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}

int		who_max(t_stack *array)
{
	int i;
	int j;

	i = 0;
	j = array->array[0];
	while (i <= array->top)
	{
		if (j < array->array[i])
			j = array->array[i];
		i++;
	}
	return (j);
}

void		teleport(t_lem *lem)
{
	int row;
	int col;

	push(lem->route, 0);
	row = -1;
	while (who_max(lem->route) != ret_index(lem->end, lem->room))//++row <= lem->room_size + 2)
	{
		col = lem->room_size + 2;
		while (--col >= 0)
		{
			if (lem->map->array[row][col] == 1)
			{
				lem->map->array[row][col] = 0;
				push(lem->route, col);
				row = col;
				lem->map->array[row][col] = 0;
				display_map(lem);
			}
		}
	}	
}
