/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:02:49 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/19 10:20:41 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_H
# define LEM_H
# include "get_next_line/get_next_line.h"

typedef struct  s_cord
{
	char		*x;
	char		*y;
}				t_cord;

typedef struct	s_stack
{
	int			top;
	int			*array;
	int			size;
}				t_stack;

typedef struct	s_cordstack
{
	int			top;
	t_cord		*cord;
	int			size;
}				t_cordstack;

typedef struct	s_room
{
	int			top;
	char		**array;
	//char		*name;
	//int		id;
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
	t_room			*room;
	t_cordstack		*relations;
	t_stack			*route;
	t_map			*map;
	t_gnl			gnl;
	int				ants;
	int				ac;
	char			**av;
	char			**hold;
	int				hold_size;
}				t_lem;
#endif
/*
** ======================================================== display.c
*/
void		display_stack(t_stack *stack);
void		display_map(t_stack *map);
/*
** ======================================================== admin.c
*/
void		ft_initial(t_lem *lem);
void		dupe_err(t_lem *lem);
void		ft_relations(t_lem *lem, int i);
/*
** ======================================================== create.c
*/
t_stack		*new_stack(size_t size);
int			stack_state(t_stack *lem);
void		push(t_stack *lem, int integer);
int			pop(t_stack *lem);
int			ret_index(int value, t_stack *stack);
/*
** ======================================================== parse.c
*/
void		store_data(t_lem *lem);
void		parse_data(t_lem *lem);
