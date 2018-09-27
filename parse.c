/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 07:15:04 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/27 18:35:51 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		ft_alloc_arr(t_lem *l)
{
	int		init_size;
	char	**dup;
	int		i;

	i = -1;
	init_size = l->hold_size;
	if (l->hold != NULL)
	{
		dup = (char **)malloc(sizeof(char *) * (init_size + 2));
		while (++i < init_size)
			swapnfree(&dup[i], ft_strndup(l->hold[i], ft_strlen_n(l->hold[i], ' ')));
		swapnfree(&dup[i++], ft_strndup(l->all[l->i], ft_strlen_n(l->all[l->i], ' ')));
		dup[i] = 0;
		l->hold = dup;
	}
	else
	{
		l->hold = (char **)malloc(sizeof(char *) * 2);
		l->hold[0] = ft_strndup(l->all[l->i], ft_strlen_n(l->all[l->i], ' '));
		l->hold[1] = 0;
	}
	l->hold_size++;
}

void		ft_all_arr(t_lem *l)
{
	int		init_size;
	char	**dup;
	int		i;

	i = -1;
	init_size = l->all_size;
	if (l->all != NULL)
	{
		dup = (char **)malloc(sizeof(char *) * (init_size + 2));
		while (++i < init_size)
		{
			dup[i] = ft_strdup(l->all[i]);
			free(l->all[i]);
		}
		dup[i++] = ft_strdup(l->gnl.line);
		dup[i] = 0;
		l->all = dup;
	}
	else
	{
		l->all = (char **)malloc(sizeof(char *) * 2);
		l->all[0] = ft_strdup(l->gnl.line);
		l->all[1] = 0;
	}
	l->all_size++;
}
/*
void		ft_all_arr(t_lem *l)
{
	int		init_size;
	char	**dup;
	int		i;

	i = -1;
	init_size = l->all_size;
	if (l->all != NULL)
	{
		dup = (char **)malloc(sizeof(char *) * (init_size + 2));
		while (++i < init_size)
		{
			dup[i] = ft_strdup(l->all[i]);
			free(l->all[i]);
		}
		dup[i++] = ft_strdup(l->gnl.line);
		dup[i] = 0;
		l->all = dup;
	}
	else
	{
		l->all = (char **)malloc(sizeof(char *) * 2);
		l->all[0] = ft_strdup(l->gnl.line);
		l->all[1] = 0;
	}
	l->all_size++;
}
*/
void		store_data(t_lem *lem)
{
	int i;

	i = 0;
	while (get_next_line(0, &(lem->gnl.line)) > 0)
	{
		ft_all_arr(lem);
		if (ft_strncmp(lem->all[lem->i], "##start", 7) == 0)
			lem->i++;
		else if (ft_strncmp(lem->all[lem->i], "##end", 5) == 0)
			lem->i++;
		else if (ft_contain_char(lem->all[lem->i], '-') == 1)
			lem->relations_size++;
		else if (ft_contain_char(lem->all[lem->i], '#') == 0)
			lem->room_size++;
	}
	no_path(lem);
}

/* BACKUP
void		store_data(t_lem *lem)
{
	int i;

	i = 0;
	while (get_next_line(0, &(lem->gnl.line)) > 0)
		ft_all_arr(lem);
	no_path(lem);
}*/


void		parse_data(t_lem *lem)
{
	lem->ants = ft_atoi(lem->all[lem->i]);
	while (++lem->i < lem->all_size)
	{
		if (ft_strncmp(lem->all[lem->i], "##start", 7) == 0)
		{
		//	lem->i++;
			lem->start = ft_strsub(lem->all[lem->i], 0,
					ft_strlen_n(lem->all[lem->i], ' '));
		}
		else if (ft_strncmp(lem->all[lem->i], "##end", 5) == 0)
		{
		//	lem->i++;
			lem->end = ft_strsub(lem->all[lem->i], 0,
					ft_strlen_n(lem->all[lem->i], ' '));
		}
		else if (ft_contain_char(lem->all[lem->i], '-') == 1)
		{
			ft_alloc_arr(lem);
		//	lem->relations_size++;
		}
		else if (ft_contain_char(lem->all[lem->i], '#') == 0)
		{
			ft_alloc_arr(lem);
		//	lem->room_size++;
		}
	}
}

void	room_stack(t_lem *lem)
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

void	relations_stack(t_lem *lem)
{
	int i;
	int j;

	i = lem->room_size;
	j = -1;
	lem->relations = new_room_arr(lem->relations_size + 1);
	while (++j < lem->relations_size)
		lem->relations->array[j] = ft_strdup(lem->hold[i++]);
	lem->relations->array[lem->relations_size + 1] = 0;
}

void	pop_map(t_lem *lem)
{
	lem->map = new_map((lem->room_size + 2));
	int j;
	int k;

	j = -1;
	while (++j < (lem->room_size + 2))
	{
		k = -1;
		while (++k < (lem->room_size + 2))
				lem->map->array[j][k] = 0;
	}
	one_or_zero(lem);
}
