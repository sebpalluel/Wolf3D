/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:19:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/13 17:29:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

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
	if (SETUP.key == ZERO && SETUP.sky_num != 0)
		ft_sky_apply(setup, SKY_PATH_0, 0);
	else if (SETUP.key == ONE && SETUP.sky_num != 1)
		ft_sky_apply(setup, SKY_PATH_1, 1);
	else if (SETUP.key == TWO && SETUP.sky_num != 2)
		ft_sky_apply(setup, SKY_PATH_2, 2);
	else if (SETUP.key == THREE && SETUP.sky_num != 3)
		ft_sky_apply(setup, SKY_PATH_3, 3);
	else if (SETUP.key == FOUR && SETUP.sky_num != 4)
		ft_sky_apply(setup, SKY_PATH_4, 4);
	else if (SETUP.key == FIVE && SETUP.sky_num != 5)
		ft_sky_apply(setup, SKY_PATH_5, 5);
	if (SKY != NULL)
		return (OK);
	return (ERROR);
}

void	ft_mlx_control(t_setup *setup)
{
	int	x;

	x = S_WIDTH / 1.5;
	if (!SETUP.ui)
	{
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 16, 0xccccff, L_CONTROLS);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 32, 0xccccff, L_UP);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 48, 0xccccff, L_DOWN);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 64, 0xccccff, L_LEFT);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 80, 0xccccff, L_RIGHT);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 96, 0xccccff, L_PLUS);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 112, 0xccccff, L_MINUS);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 128, 0xccccff, L_MAP);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 144, 0xccccff, L_HIDE);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 160, 0xccccff, L_EASY);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 176, 0xccccff, L_MEDIUM);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 192, 0xccccff, L_HARD);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 208, 0xccccff, L_RESET);
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x, 224, 0xccccff, L_ESC);
	}
}
