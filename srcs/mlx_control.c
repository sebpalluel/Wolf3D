/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/02 14:19:33 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/03 13:29:18 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_print_color(t_setup *setup)
{	
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 100, 16711680,
			" key Q/W   LERP_IN R:");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 5, 100, 16711680,
			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[0]->r)));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 120, 65280,
			" key A/S   LERP_IN G:");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 5, 120, 65280,
			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[0]->g)));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 140, 255,
			" key Z/X   LERP_IN B:");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 5, 140, 255,
			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[0]->b)));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 100, 16711680,
			" key E/R   LERP_OUT R:");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 2.15, 100, 16711680,
			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[1]->r)));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 120, 65280,
			" key D/F   LERP_OUT G:");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 2.15, 120, 652805,
			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[1]->g)));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 140, 255,
			" key C/V   LERP_OUT B:");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 2.15, 140, 255,
			ft_ftoa((int)(SETUP.fract[SETUP.f_mode]->clr[1]->b)));
}

static void	ft_print_fract_info(t_setup *setup)
{
	if (SETUP.f_mode == 0)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
				" mandelbrot");
	if (SETUP.f_mode == 1)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215, " julia");
	if (SETUP.f_mode == 2)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215,
				" burningship");
	if (SETUP.f_mode == 3)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215, " cantor");
	if (SETUP.f_mode == 4)
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 0, 16777215, " all");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 20, 16777215,
			" key -/+   iteration max : ");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 20, 16777215,
			ft_ftoa(SETUP.fract[SETUP.f_mode]->it_max));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 40, 16777215, " pos x/y : ");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 8, 40, 16777215,
			ft_ftoa(SETUP.fract[SETUP.f_mode]->vec.x));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, setup->width / 4, 40, 16777215,
			ft_ftoa(SETUP.fract[SETUP.f_mode]->vec.y));
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 60, 8224125,
			" switch to fract [1] mandelbrot [2] julia [3] burningship \
			[4] cantor [0] all");
}

void		ft_print(t_setup *setup)
{
	ft_print_fract_info(setup);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, 0, 80, 8224125,
			" to reset position press P");
	ft_print_color(setup);
}

void		ft_form_fract(int keycode, t_setup *setup)
{
	int		frac;

	frac = -1;
	if (SETUP.f_mode < FNUM - 1)
	{
		if (keycode == MINUS && SETUP.fract[SETUP.f_mode]->it_max > 10)
			SETUP.fract[SETUP.f_mode]->it_max -= 10;
		if (keycode == EQUAL && SETUP.fract[SETUP.f_mode]->it_max < 250)
			SETUP.fract[SETUP.f_mode]->it_max += 10;
	}
	if (SETUP.f_mode == FNUM)
	{
		if (keycode == MINUS)
			while (++frac < FNUM && SETUP.fract[frac]->it_max > 10)
				SETUP.fract[frac]->it_max -= 10;
		if (keycode == EQUAL)
			while (++frac < FNUM && SETUP.fract[frac]->it_max < 250)
				SETUP.fract[frac]->it_max += 10;
	}
}
void	ft_switch_fract(int keycode, t_setup *setup)
{
	if (keycode == ONE)
		SETUP.f_mode = 0;
	if (keycode == TWO)
		SETUP.f_mode = 1;
	if (keycode == THREE)
		SETUP.f_mode = 2;
	if (keycode == FOUR)
		SETUP.f_mode = 3;
	if (keycode == ZERO)
		SETUP.f_mode = 4;
}

void	ft_change_color(int keycode, t_setup *setup)
{
	if (keycode == Q_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->r > 0)
		SETUP.fract[SETUP.f_mode]->clr[0]->r -= 5;
	if (keycode == A_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->g > 0)
		SETUP.fract[SETUP.f_mode]->clr[0]->g -= 5;
	if (keycode == Z_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->b > 0)
		SETUP.fract[SETUP.f_mode]->clr[0]->b -= 5;
	if (keycode == W_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->r < 255)
		SETUP.fract[SETUP.f_mode]->clr[0]->r += 5;
	if (keycode == S_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->g < 255)
		SETUP.fract[SETUP.f_mode]->clr[0]->g += 5;
	if (keycode == X_KEY && SETUP.fract[SETUP.f_mode]->clr[0]->b < 255)
		SETUP.fract[SETUP.f_mode]->clr[0]->b += 5;
	if (keycode == E_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->r > 0)
		SETUP.fract[SETUP.f_mode]->clr[1]->r -= 5;
	if (keycode == D_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->g > 0)
		SETUP.fract[SETUP.f_mode]->clr[1]->g -= 5;
	if (keycode == C_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->b > 0)
		SETUP.fract[SETUP.f_mode]->clr[1]->b -= 5;
	if (keycode == R_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->r < 255)
		SETUP.fract[SETUP.f_mode]->clr[1]->r += 5;
	if (keycode == F_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->g < 255)
		SETUP.fract[SETUP.f_mode]->clr[1]->g += 5;
	if (keycode == V_KEY && SETUP.fract[SETUP.f_mode]->clr[1]->b < 255)
		SETUP.fract[SETUP.f_mode]->clr[1]->b += 5;
}


