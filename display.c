/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:54:52 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/26 13:26:03 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	display_stack(t_stack *stack)
{
	int i;

	i = stack->top;
	while (i >= 0)
	{
		if (i >= 0)
		{
			ft_putnbr_fd(stack->array[i], 2);
			ft_putchar_fd('\t', 2);
		}
		else
			ft_putstr_fd("--\t", 2);
		i--;
	}
	ft_putstr_fd("--\nROUTE\n", 2);
}

void	display_map(t_lem *lem, int flag)
{
	if (flag == 0)
		return ;
	int i;
	int j;
	int k;
	int r;

	i = 0;
	j = 0;
	k = 0;
	r = lem->route->top;
	ft_putstr_fd(" ", 2);
	while (i < (lem->room_size + 2))
	{
		ft_putstr_fd(" ", 2);
		ft_putnbr_fd(i, 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
	while (j < (lem->room_size + 2))
	{
		k = 0;
		ft_putnbr_fd(j, 2);
		while (k < (lem->room_size + 2))
		{
			ft_putchar_fd(' ', 2);
			ft_putnbr_fd(lem->map->array[j][k], 2);
			k++;
		}
		ft_putstr_fd("\t\t", 2);
		if (r >= 0)
		{
			ft_putnbr_fd(lem->route->array[r], 2);
			ft_putchar_fd('\t', 2);
		}
		else
			ft_putstr_fd("--\t", 2);
		r--;
		ft_putchar_fd('\n', 2);
		j++;
	}
	ft_putchar_fd('\n', 2);
}

void	err_message(int i)
{
	if (i == 0)
	{
		ft_putendl("Error: Duplicate Rooms Declared");
		exit(0);
	}
	else if (i == 1)
	{
		ft_putendl("Error: No Start or End Room Declared");
		exit(0);
	}
	else if (i == 2)
	{
		ft_putendl("Error: Linked Room Not Declared");
		exit(0);
	}
	else if (i == 3)
	{
		ft_putendl("Error: Ant Data Invalid");
		exit(0);
	}
	else if (i == 4)
	{
		ft_putendl("Error: No Path Possible");
		exit(0);
	}
	else if (i == 5)
	{
		ft_putendl("Error: Duplicate Paths Declared");
		exit(0);
	}
}
