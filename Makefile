#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/09 14:05:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/10/18 13:30:41 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = wolf3d

SRC 		=	srcs/wolf3d.c \
				srcs/setup.c \
				srcs/mlx_process.c \
				srcs/mlx_control.c \
				srcs/path_maker.c \
				srcs/path_maker_dir.c \
				srcs/configure_map.c \
				srcs/save_map.c \
				srcs/generate_map.c \
				srcs/open_map.c \
				srcs/draw.c \
				srcs/ray_casting.c \
				srcs/player.c \
				srcs/color.c \

EXT			=	Makefile

OBJ			=	$(SRC:.c=.o)

CMP			=	gcc

DEBUG		=	-g3 -fsanitize=address

FLAGS		=	-Wall -Wextra -Werror -lpthread 

LIB_DIR		=	-L libft/ -L minilibx/
LIBS		=	-lft -lmlx -framework OpenGL -framework AppKit

all : lib $(NAME) compil

$(NAME) : $(OBJ) $(EXT)

compil :
	@$(CMP) $(FLAGS) -o $(NAME) $(SRC) $(LIB_DIR) $(LIBS)
	@echo "wolf3d compiled"

debug_compil :
	@$(CMP) $(FLAGS) $(DEBUG) -o $(NAME) $(SRC) $(LIB_DIR) $(LIBS)
	@echo "wolf3d compiled"

lib :
	@echo "compiling libft..."
	@make -C libft/ --no-print-directory
	@echo "libft compiled"
	@echo "compiling mlx..."
	@make -C minilibx/ --no-print-directory
	@echo "mlx compiled"

clean :
	@echo "cleaning objects..."
	@rm -f $(OBJ)
	@rm -rf $(NAME).dSYM
	@make -C libft/ clean --no-print-directory
	@echo "cleaning mlx..."
	@make -C minilibx/ clean --no-print-directory
	@echo "clean done"

fclean : clean
	@rm -f $(NAME)
	@echo "full cleaning libft..."
	@make -C libft/ fclean --no-print-directory
	@echo "fclean done"

re : fclean all

debug : lib $(NAME) debug_compil

.PHONY: $(NAME) all clean fclean re
