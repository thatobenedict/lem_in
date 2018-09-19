/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 13:05:38 by tbenedic          #+#    #+#             */
/*   Updated: 2018/09/19 09:04:02 by tbenedic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define MIN (-MAX - 1)
# define MAX 2147483647
# define BUFF_SIZE 1
# define READ_SUCCESS 1
# define READ_COMPLETE 0
# define READ_ERROR -1
# include "libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>


int		get_next_line(const int fd, char **line);

#endif
