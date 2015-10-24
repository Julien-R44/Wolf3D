# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jripoute <jripoute@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/04 16:08:44 by y0ja              #+#    #+#              #
#    Updated: 2015/03/25 14:32:58 by jripoute         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= wolf3d
LLIBFT= -L./libft/ -lft 
CLIBFT= -I./libft/include/ 
LIBX = ./minilibx/ 
LFLAGS= $(LLIBFT) -L./minilibx/ -lmlx_Linux -lX11 -lm -lbsd
#FLAGS = -Ofast -I./includes/ -I/usr/X11R6/include -g \
		-framework OpenGL -framework AppKit

CFLAGS= -I./includes/ $(CLIBFT) -I$(LIBX)

SRC = \
		main.c parser.c hooks.c misc.c init.c moves.c hud.c \
		raycast_dda.c raycast_floorcasting.c textures.c free.c \
		draw.c minimap.c sprites.c loot.c dooorz.c actions.c \
		textures2.c textures3.c
OBJ=$(SRC:.c=.o)
SRCDIR=./srcs/
OBJDIR=./objs/
SRCS=$(addprefix $(SRCDIR), $(SRC))
OBJS=$(addprefix $(OBJDIR), $(OBJ))

.SILENT:

all: $(NAME)

$(NAME): make_obj
	gcc -o $(NAME) $(OBJS) $(LFLAGS) 
	echo "\\033[1;32mSuccess."

make_obj:
	#make -C $(LIBX)
	make -C libft/
	gcc -c $(SRCS) $(CFLAGS)
	mkdir -p $(OBJDIR)
	mv $(OBJ) $(OBJDIR)

clean:
	echo "\\033[1;34mDeleting objects..."
	rm -f $(OBJS)

fclean: clean
	echo "\\033[1;34mDeleting wolf3d..."
	rm -f $(NAME)

re: fclean all
