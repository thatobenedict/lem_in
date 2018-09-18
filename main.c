/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:03:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/18 18:18:27 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		parse_data(t_lem *lem)
{
	int i;
	
	while (get_next_line(0, &(lem->gnl.line)) > 0)
	{
		if (i == 0)
		{
			ant_err_admin(ps);
			lem->ants = ft_atoi(lem->gnl.line);
		}
		else if (ft_strncmp(lem->gnl.line, "##start", 7) == 0)
		{
			get_next_line(0, &(lem->gnl.line));
			ft_strcpy(lem->room->array[0], lem->gnl.line);
		}
		else if (ft_strncmp(lem->gnl.line, "##end", 5) == 0)
		{
			get_next_line(0, &(lem->gnl.line));
			ft_strcpy(lem->room->end, lem->gnl.line);
		}
		else if (ft_contain_char(lem->gnl.line, '-'))
		{

		}


		i++;
	}
}


int		main(int argc, char **argv)
{
	t_lem	lem;

	lem	= ft_memalloc(sizeof(t_lem));
	ft_initial(lem);
	lem->ac = ac;
	lem->av = av;
	parse_data(lem);
	
}
