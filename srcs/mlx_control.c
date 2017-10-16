/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:19:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/16 12:57:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	ft_modify_speed(t_setup *setup)
{
	if (SETUP.key == EQUAL)
	{
		SETUP.rot_step += 0.05;
		SETUP.move_step += 0.05;
	}
	if (SETUP.key == MINUS)
	{
		SETUP.rot_step -= 0.05;
		SETUP.move_step -= 0.05;
	}
}

void	ft_mlx_control_key(t_setup *setup)
{
	if (SETUP.key == UP)
		SETUP.udlr[0] = 1;
	if (SETUP.key == DOWN)
		SETUP.udlr[1] = 1;
	if (SETUP.key == LEFT)
		SETUP.udlr[2] = 1;
	if (SETUP.key == RIGHT)
		SETUP.udlr[3] = 1;
	if (SETUP.key == G_KEY)
		SETUP.ui = !SETUP.ui ? 1 : 0;
	if (SETUP.key == C_KEY)
		MAP->cheat = !MAP->cheat ? 1 : 0;
	if (SETUP.key == B_KEY)
		MAP->skybox = !MAP->skybox ? 1 : 0;
	if (SETUP.key == D_KEY)
		MAP->drunk_mode = !MAP->drunk_mode ? 1 : 0;
	if (SETUP.key == M_KEY)
		MAP->draw_map = !MAP->draw_map ? 1 : 0;
	ft_modify_speed(setup);
}

void	ft_sky_apply(t_setup *setup, char *path, int num)
{
	if (SKY)
		ft_imgdel(SKY, MLX->mlx_ptr);
	SKY = ft_xmpnew(MLX->mlx_ptr, path, SETUP.width, SETUP.height);
	SETUP.sky_num = num;
}

int		ft_sky_select(t_setup *setup)
{
	if (SETUP.key == ONE && SETUP.sky_num != 1)
		ft_sky_apply(setup, SKY_PATH_1, 1);
	else if (SETUP.key == TWO && SETUP.sky_num != 2)
		ft_sky_apply(setup, SKY_PATH_2, 2);
	else if (SETUP.key == THREE && SETUP.sky_num != 3)
		ft_sky_apply(setup, SKY_PATH_3, 3);
	else if (SETUP.key == FOUR && SETUP.sky_num != 4)
		ft_sky_apply(setup, SKY_PATH_4, 4);
	else if (SETUP.key == FIVE && SETUP.sky_num != 5)
		ft_sky_apply(setup, SKY_PATH_5, 5);
	else if (SETUP.key == SIX && SETUP.sky_num != 0)
		ft_sky_apply(setup, SKY_PATH_0, 0);
	if (SKY != NULL)
		return (OK);
	return (ERROR);
}

void	ft_mlx_control(t_setup *setup)
{
	int	x;

	x = S_WIDTH / 1.5;
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 16, 0xffccff, UP_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 32, 0xffccff, DOWN_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 48, 0xffccff, LEFT_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 64, 0xffccff, RIGHT_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 80, 0xccffff, PLUS_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 96, 0xccffff, MINUS_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 112, 0xccffee, DRUNK_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 128, 0xccccff, MAP_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 144, 0xccccff, GUI_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 160, 0xccccff, SKY_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 176, 0xccccff, CHEAT_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 192, 0xffffff, S_MODE_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 208, 0xFFcccc, ESC_STR);
}
