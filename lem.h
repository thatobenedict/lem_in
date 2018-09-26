/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 11:02:49 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/25 18:20:35 by tbenedic         ###   ########.fr       */
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
	int			t_row; // future proof - incase of norm
	int			t_col; // future proof - incase of norm
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
void		one_or_zero(t_lem *l);//(int row, int col, t_lem *l);
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
void		ft_alloc_arr(t_lem *l);
void		store_data(t_lem *lem);
void		parse_data(t_lem *lem);
void		room_stack(t_lem *lem);
void		relations_stack(t_lem *lem);
void		pop_map(t_lem *lem);
/*
** ======================================================== create_new_arr.c
*/
t_room		*new_room_arr(size_t size);
t_map		*new_map(size_t size);
/*
** ======================================================== algo.c
*/
void		teleport(t_lem *lem);
void			if_push(t_lem *lem, int row, int col);
void			if_pop(t_lem *lem, int row, int col);
void		ant_moves(t_lem *lem);
