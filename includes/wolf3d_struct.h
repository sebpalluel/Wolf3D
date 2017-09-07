/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:32:54 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/07 21:28:40 by psebasti         ###   ########.fr       */
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

typedef struct		s_player
{
	t_vec3			pos;
	t_vec3			dir;
	t_vec3			plane;
	size_t			randpos;
}					t_player;

typedef struct		s_ray
{
	char			stepx;
	char			stepy;
	int				mapx;
	int				mapy;
	double			size;
	char			side;
	char			touch;
	t_pix			*sdist;
	t_pix			*ddist;
	t_pix			*dir;
	t_pix			*pos;
}					t_ray_cast;

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
	t_color			*west;
	t_color			*east;
	t_color			*north;
	t_color			*south;
	t_color			*ground;
	size_t			**map;
	char			**map_str;
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
	t_player		*player;
	t_ray_cast		*ray_cast;
	t_fd			*fd;
}					t_setup;

#endif
