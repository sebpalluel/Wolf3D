/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/03 18:52:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				ft_setup_menu(t_setup *setup)
{
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 50, 0x00611DE9, MAPG_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 8, 0x009999FF, WIDTHG_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 5, 0x009999FF, HEIGHTG_STR);
	if (ft_configure_dim(setup) == ERROR)
		return (ERROR);
	if (MAP->dim_t[1] && ft_generate_map(setup) == ERROR)
		return (ERROR);
	return (OK);
}

void			ft_start(t_setup *setup)
{
	size_t		xy[2];

	xy[0] = SETUP.width / 2 - SETUP.width / 14;
	xy[1] = SETUP.height / 2 - SETUP.height / 10;
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, xy[0], xy[1], \
			0x00FFFFFF, START_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, xy[0], xy[1] + 30, \
			0x00FFFFFF, ENTER_STR);
}

static size_t	ft_setup_alloc(t_setup *setup)
{
	SETUP.width = WIDTH;
	SETUP.height = HEIGHT;
	MLX = ft_initwindow("wolf3d", SETUP.width, SETUP.height);
	IMG = ft_imgnew(MLX->mlx_ptr, SETUP.width, SETUP.height);
	SKY = ft_xmpnew(MLX->mlx_ptr, SKY_PATH, SETUP.width, SETUP.height);
	MAP = (t_map *)ft_memalloc(sizeof(t_map));
	FD = (t_fd *)ft_memalloc(sizeof(t_fd));
	RAY = (t_ray_cast *)ft_memalloc(sizeof(t_ray_cast));
	PLAY = (t_player *)ft_memalloc(sizeof(t_player));
	ft_memset(MAP, 0, sizeof(t_map));
	ft_memset(RAY, 0, sizeof(t_ray_cast));
	ft_memset(PLAY, 0, sizeof(t_player));
	ft_color(&MAP->north, 125, 0, 125);
	ft_color(&MAP->south, 125, 125, 0);
	ft_color(&MAP->east, 0, 125, 125);
	ft_color(&MAP->west, 255, 125, 125);
	ft_color(&MAP->ground, 125, 125, 125);
	ft_color(&MAP->sky, 255, 255, 255);
	if (MLX == NULL || IMG == NULL || SKY == NULL || MAP == NULL || \
			FD == NULL || RAY == NULL || PLAY == NULL)
		return (ERROR);
	return (OK);
}

static void		ft_setup_delete_mlx_img(size_t i, t_setup *setup)
{
	if (i == 0)
	{
		if (SKY)
			ft_imgdel(SKY, MLX->mlx_ptr);
		ft_mlxdelete(MLX, IMG);
	}
	else
	{
		if (setup[i].img)
			free (setup[i].img);
		if (setup[i].sky)
			free (setup[i].sky);
		if (setup[i].mlx)
			free (setup[i].mlx);
	}
}


//void		ft_setup_delete(t_setup *setup, int i)
//{
//	int			frac_n;
//	int			col_n;
//
//	frac_n = -1;
//	ft_setup_delete_mlx_img(i, setup);
//	if (setup[i].fract)
//	{
//		while (++frac_n < FNUM)
//		{
//			col_n = -1;
//			while (++col_n < 4)
//				free (setup[i].fract[frac_n]->clr[col_n]);
//			free (setup[i].fract[frac_n]->clr);
//			free (setup[i].fract[frac_n]);
//		}
//		free (setup[i].fract);
//	}
//}

size_t			ft_setup_mode(t_setup *setup, size_t mode)
{
	int			i;

	i = -1;
	if (mode)
		return (ft_setup_alloc(setup));
	else
	{
		//while (++i < NUM_THREAD)
		ft_setup_delete_mlx_img(0, setup);
		if (MAP)
		{
			ft_tabfree((void **)MAP->map_str);
			ft_tabfree((void **)MAP->map);
			free(MAP);
		}
		if (RAY)
			free(RAY);
		if (PLAY)
			free(PLAY);
		if (FD)
			free(FD);
		//		while (i < NUM_THREAD + 1)
		//		{
		//			ft_setup_delete(i, setup);
		//			i++;
		//		}
		free(setup);
		ft_putendl("program exited normally");
		//		else
		//			ft_error_usage();
		while(42);
		exit (0);
	}
}
