# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/15 19:09:16 by hvashchu          #+#    #+#              #
#    Updated: 2017/10/15 19:09:18 by hvashchu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1
SRC	= 	main.c \
		addobject.c \
		intersection.c \
		lighting.c \
		normal.c \
		raytracing.c \
		rotation.c \
		scene.c \
		vectormath.c \
		vectormath2.c

OBJ = $(SRC:.c=.o)
FLAGS = -framework OpenGL -framework AppKit -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx/
	@gcc -o $(NAME) $(OBJ) libft/*.o minilibx/*.o $(FLAGS) 
	@echo RTv1 has been made

%.o: %.c
	@gcc -c -o  $@ $<

cleanlib:
	make clean -C ./libft
	make clean -C ./minilibx

fcleanlib:
	make fclean -C ./libft
	make clean -C ./minilibx

clean: cleanlib
	@rm -f $(OBJ)
	@echo *.o have been cleaned.

fclean: clean fcleanlib
	@rm -f $(NAME)
	@echo *.a and *.o have been cleaned.

re: fclean all
