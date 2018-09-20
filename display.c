/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 08:54:52 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/20 16:13:42 by tbenedic         ###   ########.fr       */
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
	}
	ft_putstr_fd("--\t--\nA\tB\n", 2);
}

void	display_map(t_lem *lem)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (i < (lem->room_size + 2))
	{
		ft_putchar('\t');
		ft_putnbr(i);
		i++;
	}
	ft_putchar('\n');
	while (j < (lem->room_size + 2))
	{
		k = 0;
		ft_putnbr(j);
		while (k < (lem->room_size + 2))
		{
			ft_putchar('\t');
			//get ready to insert matrix adjust func
			ft_putnbr(0);
			k++;
		}
	ft_putchar('\n');
		j++;
	}
}
