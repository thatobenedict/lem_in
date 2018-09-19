/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 07:15:04 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/19 13:54:30 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	ft_alloc_arr(t_lem *l)
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
			dup[i] = ft_strdup(l->hold[i]);
			free(l->hold[i]);
		}
		dup[i++] = ft_strdup(l->gnl.line);
		dup[i] = 0;
		l->hold = dup;
	}
	else
	{
		l->hold = (char **)malloc(sizeof(char *) * 2);
		l->hold[0] = ft_strdup(l->gnl.line);
		l->hold[1] = 0;
	}
	l->hold_size++;
}

void		parse_data(t_lem *lem)
{
	int i;

	i = 0;
	lem->hold_size = 0;
	get_next_line(0, &(lem->gnl.line));
	//ant_err_admin(ps);
	lem->ants = ft_atoi(lem->gnl.line);
//	ft_alloc_arr(lem);
	while (get_next_line(0, &(lem->gnl.line)) > 0)
	{
		if (ft_strncmp(lem->gnl.line, "##start", 7) == 0)
		{
			get_next_line(0, &(lem->gnl.line));
			ft_alloc_arr(lem);
		}
		else if (ft_strncmp(lem->gnl.line, "##end", 5) == 0)
		{
			get_next_line(0, &(lem->gnl.line));
			ft_alloc_arr(lem);
		}
		else if (ft_contain_char(lem->gnl.line, '-') == 1)
		{
			i++;
			ft_alloc_arr(lem);
		//	ft_relations(lem, i);
		}
		else if (ft_contain_char(lem->gnl.line, '#') == 0)
			ft_alloc_arr(lem);
	}
}
