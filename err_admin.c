/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_admin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 16:00:24 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/27 12:43:37 by tbenedic         ###   ########.fr       */
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

void	no_room(char *room1, char *room2, t_lem *lem)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < lem->room_size + 2)
	{
		if (ft_strcmp(room1, lem->room->array[i]) == 0 ||
				ft_strcmp(room2, lem->room->array[i]) == 0)
			j++;
	}
	if (j < 2)
		exit (0);
}

void	no_ants(t_lem *lem)
{
	int j;

	j = -1;
	while (lem->all[0][++j] != '\0')
	{
		if ((lem->all[0][j] == '+' || lem->all[0][j] == '-'))
		{
			if (ft_isdigit(lem->all[0][++j]) == 0)
				exit(0);
		}
		else
		{
			if (ft_isdigit(lem->all[0][j]) == 0)
				exit(0);
		}
	}
	if (ft_atol(lem->all[0]) < -2147483648 ||
			ft_atol(lem->all[0]) > 2147483647)
		exit(0);
	if (ft_atoi(lem->all[0]) <= 0)
		exit(0);
}

void	no_path(t_lem *lem)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < lem->all_size)
	{
		if (ft_contain_char(lem->all[i], '-') == 1)
			j++;
	}
	if (j <= 0)
		exit (0);
}
