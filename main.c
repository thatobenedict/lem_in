/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:03:02 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/17 17:34:33 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem.h"

void	display_stack(t_stack *a)
{
	int i;
	int j;

	i = a->top;
	j = b->top;
	while (i >= 0)
	{
		if (i >= 0)
		{
			ft_putnbr_fd(a->array[i], 2);
			ft_putchar_fd('\t', 2);
		}
		else
			ft_putstr_fd("--\t", 2);
	}
	ft_putstr_fd("--\t--\nA\tB\n", 2);
}

int		main(int argc, char **av)
{
	
}
