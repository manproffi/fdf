# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/09 19:20:56 by sprotsen          #+#    #+#              #
#    Updated: 2017/07/09 19:20:59 by sprotsen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIB_NAME = ft

LIB_NAME2 = ftprintf

LIB_DIR = ./libft

LIB_DIR2 = ./ft_printf

LIB_ALL = -L$(LIB_DIR) -l$(LIB_NAME) -L$(LIB_DIR2) -l$(LIB_NAME2)

SRC = main.c  fun_struct_ind.c drawing.c turn.c  brezenhame.c drawing2.c \
	brezenhame2.c main2.c main3.c


OBJ = $(SRC:.c=.o)

FLAG = -Wall -Wextra -Werror

FLG = -lmlx -framework OpenGL -framework AppKit

all:	$(NAME)

$(NAME): lib $(OBJ)
	gcc $(FLG) $(FLAG) $(OBJ) -o $(NAME) $(LIB_ALL)

%.o: %.c
	gcc $(FLAG) -c -o $@ $<

lib:
	@make -C libft
	@make -C ft_printf

clean:
	$(MAKE) clean -C libft
	$(MAKE) clean -C ft_printf
	rm -f $(OBJ)

fclean:	clean
	$(MAKE) fclean -C libft
	$(MAKE) fclean -C ft_printf
	rm -f $(NAME)

re: fclean lib all	


