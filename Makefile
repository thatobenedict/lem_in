# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 18:18:38 by tbenedic          #+#    #+#              #
#    Updated: 2018/09/26 17:02:21 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = $(addsuffix .c, $(FUNC))
FUNC = admin create create_arrays display main parse algo err_admin\
	   get_next_line/get_next_line
LIBFT = get_next_line/libft/libft.a
HEAD  = lem.h

all: $(NAME)

$(NAME):
	make -C get_next_line/libft
	gcc -Wall -Werror -Wextra $(SRC) $(LIBFT) -o $(NAME)

local:
	gcc -Wall -Werror -Wextra $(SRC) $(LIBFT) -o $(NAME)

clean: libclean

fclean: clean libfclean
		rm -f $(NAME)

libclean:
		@make clean -C ./get_next_line/libft/
libfclean:
		@make fclean -C ./get_next_line/libft/

re: fclean all
