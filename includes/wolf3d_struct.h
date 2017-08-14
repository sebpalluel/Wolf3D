/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:32:54 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/14 19:02:45 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_STRUCT_H
# define WOLF3D_STRUCT_H

typedef struct		s_setup 
{
	size_t			width;
	size_t			height;
	size_t			ui;
	t_mlx			*mlx;
	t_img			*img;
}					t_setup;

#endif
