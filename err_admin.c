/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:00:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/26 18:18:22 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	duplicate_rooms(t_lem *lem)
{
	int i;
	int j;

	i = -1;
	while (++i < lem->room_size)
	{
		j = i + 1;
		while (j < lem->room_size)
		{
			if (ft_strcmp(lem->room->array[i], lem->room->array[j]) != 0)
				j++;
			else
				exit (0);
		}
	}
}

void	no_start_end(t_lem *lem)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < lem->all_size)
	{
		if (ft_strcmp(lem->all[i], "##start") == 0 ||
				ft_strcmp(lem->all[i], "##end") == 0)
			j++;
	}
	if (j != 2)
		exit (0);
}
