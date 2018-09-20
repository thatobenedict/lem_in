/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:03:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/20 14:51:39 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

int		main(int argc, char **argv)
{
	t_lem	*lem;

	lem	= ft_memalloc(sizeof(t_lem));
	ft_initial(lem);
	lem->ac = argc;
	lem->av = argv;
	parse_data(lem);
	room_stack(lem);
	display_map(lem);
/*	//===================
	ft_putnbr(lem->ants);
	ft_putstr("\n");
	//===================
	ft_putstr(lem->start);
	ft_putstr("\n");
	//===================
	ft_putstr(lem->end);
	ft_putstr("\n");
	//===================
	ft_puttab(lem->hold);
	//===================
	ft_putstr("Check the index\n");
	ft_putstr(lem->hold[0]);
	ft_putstr("\n");
	ft_putstr(lem->hold[5]);
	ft_putstr("\n");
	//==================
	ft_putstr("Rooms Stack\n");
	ft_puttab(lem->room->array);
	ft_putstr("\n");*/
}
