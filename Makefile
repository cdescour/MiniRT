# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/25 21:52:45 by cdescour          #+#    #+#              #
#    Updated: 2023/01/26 14:31:38 by cdescour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
SRC = main.c args.c free.c file.c gnl.c obj.c obj2.c\
      a_light.c light.c cam.c cyl.c sph.c pln.c
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra -g3
DANGER = -fsanitize=address

all: $(NAME)

dependency:
	make -sC libft
	make -sC mlx42

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o}

$(NAME): dependency $(OBJ)
	gcc $(DANGER) -o $(NAME) $(OBJ) -Llibft -lft mlx42/libmlx.a
clean: 
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@make fclean -sC libft
	@make clean -sC mlx42

re: fclean all

.PHONY: all dependency clean fclean re
