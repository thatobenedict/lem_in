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
/*
** Room in this context pertains to the matrix column from the teleport function
*/
int		if_push(t_lem *lem, int row, int col)
{
	int i;

	i = lem->route->top + 1;
	while (--i >= 0)
	{
		if(lem->route->array[i] == col)
			return (row);
	}
	push(lem->route, col);
	return (col);
}

int		if_pop(t_lem *lem)
{
	if (lem->route->top == 0)
	{
	
	}
	while (--i >= 0)
	{
		if(lem->route->array[i] == col)
			return (row);
	}
	pop(lem->route);
	return (col);
}

void		teleport(t_lem *lem)
{
	int row;
	int col;

	push(lem->route, 0);
	display_map(lem);
	row = -1;
	while (++row < lem->room_size + 2) //turned this to strictly less than
	{
		if_pop(lem->route, col); // this is where a pop would need to occur
		col = lem->room_size + 2;
		row = lem->route->array[lem->route->top];
		while (--col >= 0)
		{
			if (lem->map->array[row][col] == 1)
			{
				lem->map->array[row][col] = 0;
			//	display_map(lem);
				row = if_push(lem, row, col);
				lem->map->array[row][col] = 0;
				display_map(lem);
				if (row == lem->room_size + 2)
					exit (0);
			}
		}
	}	
}
