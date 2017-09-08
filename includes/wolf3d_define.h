/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:31:26 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/08 19:15:30 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINE_H
# define WOLF3D_DEFINE_H

# define WIDTH			1330
# define HEIGHT			700
# define NUM_THREAD		8
# define AMP			1.3

# define ERROR			1
# define OK				0

# define STATE_RUN		0
# define STATE_START	1
# define STATE_GEN		2
# define STATE_SAVE		3
# define STATE_OPEN		4
# define STATE_DRAW		5

# define SETUP			setup[0]
# define S_WIDTH		setup[0].width
# define S_HEIGHT		setup[0].height
# define MAP			setup[0].map
# define M_WIDTH		setup[0].map->mapsize[0]
# define M_HEIGHT		setup[0].map->mapsize[1]
# define M_DEPTH		setup[0].map->depth
# define PATH			setup[0].map->path
# define CAM			setup[0].cam
# define MLX			setup[0].mlx
# define IMG			setup[0].img
# define FD				setup[0].fd
# define PLAY			setup[0].player
# define RAY			setup[0].ray_cast

# define MAX_ELEM		2
# define M_MIN_SIZE		3
# define M_MAX_SIZE		200


# define GO_DOWN		0
# define GO_lEFT		1
# define GO_RIGHT		2
# define GO_UP			3
# define IS_FULL		0

# define EMPTY			0
# define WALL			1
# define PATH_			2

# define MOVE_STEP		0.05
# define ROT_STEP		0.1

# define MAPG_STR		"MAP GENERATOR MODE"
# define WIDTHG_STR		"TYPE WIDTH OF MAP [ >= 3 && <= 200] AND PRESS ENTER"
# define HEIGHTG_STR	"TYPE HEIGHT OF MAP [ >= 3 && <= 200] AND PRESS ENTER"
# define SAVE_STR		"WOULD YOU LIKE TO SAVE IT ?"
# define YESORNO_STR	"y / n"
# define NAME_STR		"TYPE A NAME FOR THIS FILE AND PRESS ENTER"
# define START_STR		"Wolf3d by psebasti"
# define ENTER_STR		"Press ENTER to start"

#endif
