/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 15:52:23 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/27 18:36:02 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void		relieve_yourself(t_lem *lem)
{
	int i;

	i = -1;
	if (lem->route != NULL)
	{
		if (lem->route->array != NULL)
			free(lem->route->array);
		ft_memdel((void **)&lem->route);
	}
	if (lem->hold != NULL)
	{
		if (lem->hold != NULL)
			while (lem->hold[++i])
			{
				free(lem->hold[i]);
			}
		ft_memdel((void **)&lem->hold);
	}
	i = -1;
	if (lem->room != NULL)
	{
		if (lem->room->array != NULL)
		while (lem->room->array[++i])
		{
			free(lem->room->array[i]);
		}
		ft_memdel((void **)&lem->room);
	}
}

void			swapnfree(char **var, char *new_val)
{
	char	*tmp;

	free(*var);
	tmp = new_val;
	*var = tmp;
}
