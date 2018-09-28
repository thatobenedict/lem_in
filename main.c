/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:03:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/28 09:45:40 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	main_helper(t_lem *lem)
{
	store_data(lem);
	parse_data(lem);
	no_ants(lem);
	no_start_end(lem);
	room_stack(lem);
	relations_stack(lem);
	pop_map(lem);
	loop(lem);
}

int		main(int argc, char **argv)
{
	t_lem	*lem;

	if (argc == 1 || argc == 2)
	{
		lem = ft_memalloc(sizeof(t_lem));
		ft_initial(lem);
		lem->ac = argc;
		lem->av = argv;
		main_helper(lem);
		lem->route = new_stack(lem->room_size + 2);
		if (argc > 1)
		{
			if (ft_strcmp(argv[1], "-v") == 0)
				lem->flag = 1;
			else
				exit(0);
		}
		ft_puttab(lem->all);
		ft_putchar('\n');
		display_map(lem, lem->flag);
		teleport(lem);
		ant_moves(lem);
	}
	exit(0);
}
