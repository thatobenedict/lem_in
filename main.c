/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:03:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/26 14:45:56 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		main(int argc, char **argv)
{
	if (argc == 1 || argc == 2)
	{
		t_lem	*lem;

		lem	= ft_memalloc(sizeof(t_lem));
		ft_initial(lem);
		lem->ac = argc;
		lem->av = argv;
		parse_data(lem);
		room_stack(lem);
		relations_stack(lem);
		pop_map(lem);
		lem->route = new_stack(lem->room_size - 1);
		if (argc > 1)
		{
			if (ft_strcmp(argv[1], "-v") == 0)
				lem->flag = 1;
			else
				exit(0);
		}
		ft_putnbr(lem->ants);
		ft_putchar('\n');
		ft_putendl(lem->start);
		ft_putendl(lem->end);
		ft_puttab(lem->hold);
		ft_puttab(lem->comments);
		display_map(lem, lem->flag);
		teleport(lem);
		ant_moves(lem);
	}
	return (0);
}
