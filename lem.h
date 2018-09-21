/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:02:49 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/21 18:37:15 by tbenedic         ###   ########.fr       */
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
	int			size;
}				t_room;

typedef struct	s_map
{
	int			**array;
	int			size;
	int			top;
}				t_map;

typedef struct	s_gnl
{
	int			fd;
	char		*line;
}				t_gnl;

typedef	struct	s_lem
{
	t_room			*room;
	t_room			*relations;
	t_stack			*route;
	t_map			*map;
	t_gnl			gnl;
	int				ants;
	int				ac;
	char			**av;
	char			**hold;
	char			*start;
	char			*end;
	int				hold_size;
	int				room_size;
	int				relations_size;
}				t_lem;
#endif
/*
** ======================================================== display.c
*/
void		display_stack(t_stack *stack);
void		display_map(t_lem *map);
/*
** ======================================================== admin.c
*/
void		ft_initial(t_lem *lem);
void		dupe_err(t_lem *lem);
void		ft_relations(t_lem *lem, int i);
int			ret_index(char *name, t_room *room);
int			one_or_zero(int row, int col, t_lem *l);
/*
** ======================================================== create.c
*/
t_stack		*new_stack(size_t size);
int			stack_state(t_stack *lem);
void		push(t_stack *lem, int integer);
int			pop(t_stack *lem);
//int			ret_index(int value, t_stack *stack);
/*
** ======================================================== parse.c
*/
void		store_data(t_lem *lem);
void		parse_data(t_lem *lem);
void		room_stack(t_lem *lem);
void		relations_stack(t_lem *lem);
/*
** ======================================================== create_new_arr.c
*/
t_room		*new_room_arr(size_t size);
t_map		*new_map(size_t size);
