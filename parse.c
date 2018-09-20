/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 07:15:04 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/20 10:22:22 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"
int _g_room;
int	_g_relations;

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
		{
			dup[i] = ft_strndup(l->hold[i], ft_strlen_n(l->hold[i], ' '));
			free(l->hold[i]);
		}
		dup[i++] = ft_strndup(l->gnl.line, ft_strlen_n(l->gnl.line, ' '));
		dup[i] = 0;
		l->hold = dup;
	}
	else
	{
		l->hold = (char **)malloc(sizeof(char *) * 2);
		l->hold[0] = ft_strndup(l->gnl.line, ft_strlen_n(l->gnl.line, ' '));
		l->hold[1] = 0;
	}
	l->hold_size++;
}

void		parse_data(t_lem *lem)
{
	lem->hold_size = 0;
	get_next_line(0, &(lem->gnl.line));
	//ant_err_admin(ps);
	lem->ants = ft_atoi(lem->gnl.line);
	while (get_next_line(0, &(lem->gnl.line)) > 0)
	{
		if (ft_strncmp(lem->gnl.line, "##start", 7) == 0)
		{
			get_next_line(0, &(lem->gnl.line));
			lem->start = ft_strsub(lem->gnl.line, 0,
					ft_strlen_n(lem->gnl.line, ' '));
		}
		else if (ft_strncmp(lem->gnl.line, "##end", 5) == 0)
		{
			get_next_line(0, &(lem->gnl.line));
			lem->end = ft_strsub(lem->gnl.line, 0,
					ft_strlen_n(lem->gnl.line, ' '));
			_g_room++;
		}
		else if (ft_contain_char(lem->gnl.line, '-') == 1)
		{
			ft_alloc_arr(lem);
			_g_relations++;
		}
		else if (ft_contain_char(lem->gnl.line, '#') == 0)
			ft_alloc_arr(lem);
	}
}

void	room_stack(t_lem *lem)
{
	int i;

	i = 0;
	l->room->array = (char **)malloc(sizeof(char *) * (_g_room + 3));
	l->room->array[0] = ft_strdup(lem->start);
	while (++i < _g_room)
	{
		l->room->array[i] = ft_strdup(lem)
	}

}
