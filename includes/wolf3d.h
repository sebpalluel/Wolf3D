/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:25:18 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/20 17:48:54 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libs/libft/includes/libft.h"
# include "../includes/wolf3d_struct.h"
# include "../includes/wolf3d_define.h"
# include <stdio.h>

int		ft_error_usage();
size_t	ft_setup_mode(t_setup *setup, size_t mode);
int		ft_setup_menu(t_setup *setup);
int		ft_save_map(t_setup *setup);
void	ft_mlx_process(t_setup *setup);
void	ft_put_pxl_to_img(t_setup *setup, t_vec3 pos, t_color *clr);
int		ft_mouse_hook(int mousecode, int x, int y, t_setup *setup);
int		ft_mouse_moove(int x, int y, t_setup *setup);
int		ft_expose_hook(t_setup *setup);
void	ft_print(t_setup *setup);
void	ft_start(t_setup *setup);

#endif
