# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/28 16:44:29 by oel-yous          #+#    #+#              #
#    Updated: 2021/02/08 11:04:54 by oel-yous         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

FLAGS = -Wall -Wextra -Werror

LIB = ../libs/libft.a

FRAMEWORK = -framework OpenGl -framework AppKit -fsanitize=address

MINISRC = /usr/local/lib

SRC = main.c bmp.c render_sprite.c init_textures.c read_file.c draw.c ft_map.c\
		ft_map2.c check_path.c events.c utils_map.c utils_map2.c init.c\
		ft_error.c render3d.c get_next_line.c cast_rays.c horz_vert.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
	gcc -c $(SRC)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB) $(FLAGS) -L $(MINISRC) -lmlx $(FRAMEWORK) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f cub3D

re: fclean all