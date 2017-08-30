#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2017/01/09 14:05:27 by psebasti          #+#    #+#             *#
#*   Updated: 2017/08/30 21:02:30 by psebasti         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = wolf3d

SRC 		=	srcs/wolf3d.c \
				srcs/setup.c \
				srcs/mlx_process.c \
				srcs/path_maker.c \
				srcs/path_maker_dir.c \
				srcs/configure_map.c \
				srcs/save_map.c \
				srcs/generate_map.c \
				srcs/open_map.c \

EXT			=	Makefile

OBJ			=	$(SRC:.c=.o)

CMP			=	gcc

FLAGS		=	-ggdb -Wall -Wextra -Werror -lpthread

LIB_DIR		=	-L libs/libft/ -L libs/libft/minilibx
LIBS		=	-lft -lmlx -framework OpenGL -framework AppKit

all : lib $(NAME)

$(NAME) : $(OBJ) $(EXT)
	@$(CMP) $(FLAGS) -o $(NAME) $(SRC) $(LIB_DIR) $(LIBS)
	@echo "wolf3d compiled"

lib :
	@echo "compiling libft..."
	@make -C libs/libft/ --no-print-directory
	@echo "libft compiled"
	@echo "compiling mlx..."
	@make -C libs/libft/minilibx/ --no-print-directory
	@echo "mlx compiled"

clean :
	@rm -f $(OBJ)
	@echo "cleaning libft..."
	@make -C libs/libft/ clean --no-print-directory
	@echo "cleaning mlx..."
	@make -C libs/libft/minilibx/ clean --no-print-directory
	@echo "clean done"

fclean : clean
	@rm -f $(NAME)
	@echo "full cleaning libft..."
	@make -C libs/libft/ fclean --no-print-directory
	@echo "fclean done"

re : fclean all

.PHONY: $(NAME) all clean fclean re
