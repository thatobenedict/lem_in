/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:31:46 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/28 08:40:43 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

/*
** Room in this context pertains to the matrix column from the teleport function
*/

void		if_push(t_lem *lem, int row, int col)
{
	int i;

	row = 0;
	i = lem->route->top + 1;
	while (--i >= 0)
	{
		if (lem->route->array[i] == col)
			return ;
	}
	push(lem->route, col);
}

int			teleport_helper(t_lem *lem)
{
	push(lem->route, 0);
	display_map(lem, lem->flag);
	return (-1);
}

void		teleport(t_lem *lem)
{
	int row;
	int col;

	row = teleport_helper(lem);
	while (++row < lem->room_size + 2)
	{
		if (row != 0)
			pop(lem->route);
		col = lem->room_size + 2;
		row = lem->route->array[lem->route->top];
		while (--col >= 0)
		{
			if (lem->map->array[row][col] == 1)
			{
				lem->map->array[row][col] = 0;
				if_push(lem, row, col);
				ft_swap(&(row), &(col));
				lem->map->array[row][col] = 0;
				display_map(lem, lem->flag);
				col = lem->room_size + 2;
				if (row == lem->room_size + 1)
					return ;
			}
		}
	}
}

void		ant_moves(t_lem *lem)
{
	int ants;
	int max_ants;
	int rooms;

	ants = 1;
	rooms = -1;
	max_ants = 1;
	while (max_ants <= lem->ants)
	{
		rooms = -1;
		while (++rooms <= lem->route->top)
		{
			ft_putchar('L');
			ft_putnbr(max_ants);
			ft_putchar('-');
			ft_putstr(lem->room->array[lem->route->array[rooms]]);
			ft_putchar('\n');
		}
		max_ants++;
	}
}
