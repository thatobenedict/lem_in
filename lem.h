/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:02:49 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/18 18:18:31 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include "get_next_line/get_next_line.h"

typedef struct	s_stack
{
	int			top;
	int			*array;
	int			size;
}				t_stack;

typedef struct	s_room
{
	int			top;
	char		**array;
	char		*end;
	int			size;
}				t_room;

typedef struct	s_map
{
	int			**array;
}				t_map;

typedef struct	s_gnl
{
	int			fd;
	char		*line;
}				t_gnl;

typedef	struct	s_lem
{
	t_room		*room;
	t_stack		*relations;
	t_stack		*route;
	t_map		*map;
	t_gnl		gnl;
	int			ants;
	int			ac;
	char		**av;
}				t_lem;
#endif
/*
** ======================================================== display.c
*/
void	display_stack(t_stack *stack);
void	display_map(t_stack *map);
/*
** ======================================================== admin.c
*/
void	ft_initial(t_lem *lem);
/*
** ======================================================== create.c
*/
t_stack	*new_stack(size_t size);
int		stack_state(t_stack *lem);
void	push(t_stack *lem, int integer);
void	pop(t_stack *lem);
int		ret_index(int value, t_stack *stack);

