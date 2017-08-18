/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:32:54 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/18 19:16:27 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

typedef struct		s_map
{
	char			width[MAX_INT_DECIMAL + 1];
	size_t			width_i;
	size_t			width_t;
	char			height[MAX_INT_DECIMAL + 1];
	size_t			height_i;
	size_t			height_t;
	int				mapsize[2];
	float			mid[2];
	t_color			*lerp_in;
	t_color			*lerp_out;
	t_color			*curr_clr;
	t_pix			*pix;
	int				**tmp_map;
	t_pix			**map;
}					t_map;

typedef struct		s_setup 
{
	size_t			width;
	size_t			height;
	size_t			ui;
	size_t			mode;
	size_t			mapsize[2];
	int				ac;
	char			**args;
	int				key;
	t_mlx			*mlx;
	t_img			*img;
	t_map			*map;
}					t_setup;

#endif
