/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/18 20:41:10 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

//static size_t	ft_setup_fract_init(t_setup *setup)
//{
//	size_t i;
//	size_t j;
//
//	i = 0;
//	if (!(setup->fract = (t_fract **)ft_memalloc(sizeof(t_fract *) * FNUM + 1)))
//		return (ERROR);
//	while (i < FNUM)
//	{
//		if(!(setup->fract[i] = (t_fract *)ft_memalloc(sizeof(t_fract)))\
//				|| !(setup->fract[i]->clr = (t_color **)\
//					ft_memalloc(sizeof(t_color *) * 4)))
//			return (ERROR);
//		j = 0;
//		while (j < 3)
//		{
//			if (!(setup->fract[i]->clr[j] = ft_colornew(0, 0, 0)))
//				return (ERROR);
//			j++;
//		}
//		setup->fract[i]->clr[j] = NULL;
//		i++;
//	}
//	setup->fract[i] = NULL;
//	return (1);
//}

//static void		ft_setup_delete_mlx_img(size_t i, t_setup *setup)
//{
//	if (i == 0)
//	{
//		if (IMG)
//			ft_imgdel(IMG, MLX->mlx_ptr);
//		if (MLX)
//			ft_mlxdelete(MLX);
//	}
//	else
//	{
//		if (setup[i].img)
//			free (setup[i].img);
//		if (setup[i].mlx)
//			free (setup[i].mlx);
//	}
//}

// static void		ft_setup_delete(size_t i, t_setup *setup)
// {
// 	int			frac_n;
// 	int			col_n;
// 
// 	frac_n = -1;
// 	ft_setup_delete_mlx_img(i, setup);
// 	if (setup[i].fract)
// 	{
// 		while (++frac_n < FNUM)
// 		{
// 			col_n = -1;
// 			while (++col_n < 4)
// 				free (setup[i].fract[frac_n]->clr[col_n]);
// 			free (setup[i].fract[frac_n]->clr);
// 			free (setup[i].fract[frac_n]);
// 		}
// 		free (setup[i].fract);
// 	}
// }

//static size_t	ft_setup_init(t_setup *setup)
//{
//	size_t		i;
//
//	i = 1;
//	while (i < NUM_THREAD + 1)
//	{
//		ft_memcpy(&setup[i], &SETUP, sizeof(t_setup));
//		setup[i].mlx = (t_mlx *)ft_memalloc(sizeof(t_mlx));
//		setup[i].img = (t_img *)ft_memalloc(sizeof(t_img));
//		if (!setup[i].mlx || !setup[i].img)
//			return (ERROR);
//		ft_memcpy(setup[i].mlx, SETUP.mlx, sizeof(t_mlx));
//		ft_memcpy(setup[i].img, SETUP.img, sizeof(t_img));
//		//		if (!ft_setup_fract_init(&setup[i]))
//		//			return (ERROR);
//		i++;
//	}
//	return (ft_fract_calc(setup));
//}

static int		ft_map_width(int keycode, t_setup *setup)
{
	if (keycode != ENTER && MAP->width_i < MAX_INT_DECIMAL)
	{
		if (ft_mlx_keytonumchar(keycode) != '\0')
		{
			MAP->width[MAP->width_i] = ft_mlx_keytonumchar(keycode);
			MAP->width_i++;
			MAP->width[MAP->width_i] = '\0';
			mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 10, \
					SETUP.height / 7, 0x00FF0000, "WIDTH : ");
			mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 6, \
					SETUP.height / 7, 0x00FF0000, MAP->width);
		}
	}
	if (keycode == ENTER)
	{
		if ((M_WIDTH = ft_atoi(MAP->width)) < 2)
			return (ERROR);
		MAP->width_t = 1;
	}
	return (OK);
}

int				ft_setup_menu(int keycode, t_setup *setup)
{
	size_t		x;
	size_t		y;

	x = SETUP.width;
	y = SETUP.height;
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x / 10, y / 10, \
			0x00611DE9, MAPG_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x / 10, y / 8, \
			0x009999FF, WIDTHG_STR);
	if (!MAP->width_t)
		ft_map_width(keycode, setup);
	else
	{
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 10, \
				SETUP.height / 7, 0x0000FF00, "WIDTH : ");
		mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 6, \
				SETUP.height / 7, 0x0000FF00, MAP->width);
	}
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, x / 10, y / 6, \
			0x009999FF, HEIGHTG_STR);
	return (OK);
}

size_t			ft_setup_mode(t_setup *setup, size_t mode)
{
	size_t		i;

	i = 0;
	if (mode)
	{
		SETUP.width = WIDTH;
		SETUP.height = HEIGHT;
		MLX = ft_initwindow("wolf3d", SETUP.width, SETUP.height);
		IMG = ft_imgnew(MLX->mlx_ptr, SETUP.width, SETUP.height);
		MAP = (t_map *)ft_memalloc(sizeof(t_map));
		MAP->width_t = 0;
		MAP->height_t = 0;
		if (MLX == NULL || IMG == NULL || MAP == NULL)
			return (ERROR);
		return (OK);
	}
	else
	{
		//		while (i < NUM_THREAD + 1)
		//		{
		//			ft_setup_delete(i, setup);
		//			i++;
		//		}
		free (setup);
		ft_putendl("program exited normally");
		//		else
		//			ft_error_usage();
		exit (0);
	}
}
