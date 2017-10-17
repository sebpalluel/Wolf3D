/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:25:18 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/16 18:46:51 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include "../includes/wolf3d_struct.h"
# include "../includes/wolf3d_define.h"
# include <stdio.h>

int			usage(int mode);
size_t		ft_setup_mode(t_setup *setup, size_t mode);
int			ft_setup_menu(t_setup *setup);
int			ft_save_map(t_setup *setup);
void		ft_draw_map(t_setup *setup);
void		ft_put_pixel(t_setup *setup, int x, int y, int color);
void		ft_mlx_process(t_setup *setup);
void		ft_put_pxl_to_img(t_setup *setup, t_vec3 pos, t_color *clr);
int			ft_mouse_hook(int mousecode, int x, int y, t_setup *setup);
int			ft_mouse_moove(int x, int y, t_setup *setup);
int			ft_expose_hook(t_setup *setup);
void		ft_print(t_setup *setup);
void		ft_start(t_setup *setup);
void		ft_path_maker(t_setup *setup);
int			ft_configure_dim(t_setup *setup);
size_t		ft_name_input(t_setup *setup);
size_t		ft_generate_map(t_setup *setup);
void		ft_path_maker_dir(t_setup *setup);
size_t		ft_open_map(t_setup *setup);
void		ft_pos_player(t_setup *setup);
size_t		ft_ray_casting(t_setup *setup);
void		ft_mlx_control(t_setup *setup);
void		ft_mlx_control_key(t_setup *setup);
int			ft_sky_select(t_setup *setup);
int			ft_quit(t_setup *setup);
int			ft_select_color(t_setup *setup);
int			ft_give_color(t_setup *setup, t_color *color, int alpha);
void		ft_draw_vert_line(t_setup *setup, int posx, int len);

#endif
