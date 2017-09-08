/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:01:08 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/08 20:26:14 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_expose_hook(t_setup *setup)
{
	int		ret;

	ret = OK;
	ft_imgclean(IMG, SETUP.width, SETUP.height);
	if (SETUP.mode == STATE_OPEN)
		ret = ft_open_map(setup);
	if (SETUP.mode == STATE_DRAW)
	{
		ft_pos_player(setup);
		ret = ft_ray_casting(setup);
		ft_draw_map(setup);
		mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, IMG->image, 0, 0);
	}
	printf("ret %d\n", ret);
	if (ret == ERROR)
		ft_setup_mode(&SETUP, 0);
	mlx_do_sync(MLX->mlx_ptr);
	return (0);
}

static int	ft_key_hook(int keycode, t_setup *setup)
{
	size_t	ret;
	
	SETUP.key = keycode;
	ret = OK;
	if (SETUP.key == ENTER && SETUP.mode == STATE_START)
		SETUP.mode = (SETUP.ac > 1) ? STATE_OPEN : STATE_GEN;
	if (SETUP.key == G_KEY)
		setup->ui = !setup->ui ? 1 : 0;
	if (SETUP.key == UP)
		SETUP.udlr[0] = 1;
	if (SETUP.key == DOWN)
		SETUP.udlr[1] = 1;
	if (SETUP.key == LEFT)
		SETUP.udlr[2] = 1;
	if (SETUP.key == RIGHT)
		SETUP.udlr[3] = 1;
	if (SETUP.mode == STATE_GEN)
		ret = ft_setup_menu(setup);
	if (SETUP.mode == STATE_SAVE)
		if (ft_save_map(setup) == OK)
			SETUP.mode = STATE_DRAW;
	if (SETUP.key == ESC || ret == ERROR)
		ft_setup_mode(&SETUP, 0);
	return (0);
}

 static int	ft_key_release(int keycode, t_setup *setup)
 {
 	if (keycode == UP)
 		SETUP.udlr[0] = 0;
 	if (keycode == DOWN)
 		SETUP.udlr[1] = 0;
 	if (keycode == LEFT)
 		SETUP.udlr[2] = 0;
 	if (keycode == RIGHT)
 		SETUP.udlr[3] = 0;
 	return (0);
 }

void		ft_mlx_process(t_setup *setup)
{
	if (SETUP.mode == STATE_START)
		ft_start(setup);
	mlx_hook(MLX->win_ptr, KEYPRESS, KEYPRESSMASK, ft_key_hook, setup);
	mlx_hook(MLX->win_ptr, KEYRELEASE, KEYRELEASEMASK, ft_key_release, setup);
	mlx_loop_hook(MLX->mlx_ptr, ft_expose_hook, setup);
	mlx_loop(MLX->mlx_ptr);
}

//void	ft_put_pxl_to_img(t_setup *setup, t_vec3 pos, t_color *clr)
//{
//	unsigned int	index;
//
//	index = (pos.y * setup->width) * (IMG->bbp >> 3) \
//			+ pos.x * (IMG->bbp >> 3);
//	if (pos.x < setup->width && pos.y < setup->height)
//		ft_memcpy(setup->img->image_addr + index, clr, sizeof(int));
//}
