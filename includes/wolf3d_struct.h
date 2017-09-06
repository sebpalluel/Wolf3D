/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:32:54 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/06 10:05:59 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

typedef struct		s_pathmaker
{
	t_pix			pos;
	t_pix			to_find;
	size_t			is_full;
	size_t			rand_dir;
	size_t			lrdu[4];
}
					t_pathmaker;

typedef struct		s_map
{
	t_pathmaker		path;
	char			dim[2][MAX_INT_DECIMAL + 1];
	size_t			dim_i[2];
	size_t			dim_t[2];
	size_t			yes_t;
	size_t			name_t;
	size_t			name_i;
	size_t			cheat;
	int				draw_tick;
	int				mapsize[2];
	float			mid[2];
	t_color			*lerp_in;
	t_color			*lerp_out;
	t_color			*curr_clr;
	t_pix			*pix;
	size_t			**tmp_map;
	char			**map_str;
	t_pix			**map;
}					t_map;

typedef struct		s_setup 
{
	size_t			width;
	size_t			height;
	size_t			ui;
	size_t			mode;
	int				ac;
	char			**args;
	int				key;
	t_mlx			*mlx;
	t_img			*img;
	t_map			*map;
	t_fd			*fd;
}					t_setup;

#endif
