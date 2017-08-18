/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:31:26 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/18 17:25:21 by psebasti         ###   ########.fr       */
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

# define SETUP			setup[0]
# define MAP			setup->map
# define M_WIDTH		setup->map->mapsize[0]
# define M_HEIGHT		setup->map->mapsize[1]
# define M_DEPTH		setup->map->depth
# define CAM			setup->cam
# define MLX			setup->mlx
# define IMG			setup->img

# define MAPG_STR		"MAP GENERATOR MODE"
# define WIDTHG_STR		"TYPE WIDTH AND PRESS ENTER"
# define HEIGHTG_STR	"TYPE HEIGHT AND PRESS ENTER"
#endif
