/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/18 10:05:41 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/18 16:45:04 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_stack		*new_stack(size_t size)
{
	t_stack	*lem;

	lem = (t_stack*)ft_memalloc(sizeof(t_stack));
	lem->size = size;
	lem->top = -1;
	lem->array = (int *)ft_memalloc(sizeof(int *) * lem->size);
	return (lem);
}

/*
**   new_stack function returns;
** -  1		if the stack is full,
** -  0		otherwise.
** - -1		if the stack is empty and
*/

int			stack_state(t_stack *lem)
{
	if (lem->top == (int)(lem->size - 1))
		return (1);
	else if (lem->top == -1)
		return (-1);
	else
		return (0);
}

void		push(t_stack *lem, int integer)
{
	if (stack_state(lem) == 1)
		return ;
	lem->array[++lem->top] = integer;
}

int			pop(t_stack *lem)
{
	if (stack_state(lem) == -1)
		return (-1);
	return (lem->array[lem->top--]);
}

int			ret_index(int value, t_stack *stack)
{
	int i;

	i = 0;
	while (i <= stack->top)
	{
		if (value == stack->array[i])
			return (i);
		i++;
	}
	return (-1);
}
