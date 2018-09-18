# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbenedic <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 18:18:38 by tbenedic          #+#    #+#              #
#    Updated: 2018/09/18 18:24:40 by tbenedic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = $(addsuffix .c, $(FUNC))
FUNC = main stack_basics display admin operations1 operations2 \
		operations3 operations_inline get_next_line/get_next_line
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
