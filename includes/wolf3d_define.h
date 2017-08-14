/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_define.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:31:26 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/14 19:02:41 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_DEFINE_H
# define WOLF3D_DEFINE_H

# define WIDTH		1330
# define HEIGHT		700
# define NUM_THREAD	8
# define AMP		1.3

# define ERROR		1
# define OK			0

# define MAP		setup->map
# define M_WIDTH	setup->map->width
# define M_HEIGHT	setup->map->height
# define M_DEPTH	setup->map->depth
# define CAM		setup->cam
# define MLX		setup->mlx
# define IMG		setup->img

#endif
