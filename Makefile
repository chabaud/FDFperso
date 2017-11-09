# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schabaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/15 10:50:06 by schabaud          #+#    #+#              #
#    Updated: 2016/09/16 14:55:56 by schabaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GS	=	-Wall -Werror -Wextra -ansi

HEAD	=	-I./head

LIBFT	=	-I./libft/head -L./libft -lft

MLX		= 	-L/usr/local/lib/ -I/usr/local/include -lmlx -framework	\
						OpenGL -framework AppKit

NAME	=	fdf

SRC		=	src/main.c		\
			src/map.c		\
			src/mouvement.c	\
			src/object.c	\
			src/line.c		

$(NAME): $(OBJ)

all: $(NAME)

$(NAME):
	@make -C ./libft
	@gcc -o $(NAME) $(SRC) $(HEAD) $(MLX) $(LIBFT) $(FLAGS)

clean:
	@rm -rf $(OBJ)
	@make clean -C ./libft

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(OBJ)
	@make fclean -C ./libft

make re: fclean all
