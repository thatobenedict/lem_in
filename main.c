/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:03:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/22 09:42:11 by tbenedic         ###   ########.fr       */
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
	relations_stack(lem);
	pop_map(lem);

//	int i = -1;
//	while (++i < lem->relations_size)
//	{
//		ft_putstr(lem->relations->array[i]);
//		ft_putstr("\t");
//		ft_putnbr(ft_strlen_n(lem->relations->array[i], '-'));
//		ft_putstr("\t");
//		ft_putstr(ft_strrchr(lem->relations->array[i], '-') + 1);
//		ft_putstr("\n");
//	}
	display_map(lem);
//	ft_puttab(lem->hold);
//	ft_putstr("\nRooms Stack\n");
//	ft_puttab(lem->room->array);
//	ft_putstr("\nRelations Stack\n");
//	ft_puttab(lem->relations->array);
}
