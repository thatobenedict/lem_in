/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_arrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 11:54:18 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/20 18:36:38 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

t_room		*new_room_arr(size_t size)
{
	t_room	*lem;

	lem = (t_room*)ft_memalloc(sizeof(t_room));
	lem->size = size;
	lem->top = -1;
	lem->array = (char **)ft_memalloc(sizeof(char *) * lem->size);
	return (lem);
}

t_map		*new_map(size_t size)
{
	t_map	*lem;

	lem = (t_map*)ft_memalloc(sizeof(t_map));
	lem->size = size;
	lem->top = -1;
	lem->array = (int **)ft_memalloc(sizeof(int **) * lem->size);
	return (lem);
}
