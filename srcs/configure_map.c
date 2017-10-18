/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:20:22 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 12:22:51 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		ft_map_dim(t_setup *setup, size_t *c, char *str, size_t *flag)
{
	if (setup->key != ENTER && *c < MAX_INT_DECIMAL)
	{
		if (ft_mlx_keytonumchar(setup->key) != '\0')
		{
			str[*c] = ft_mlx_keytonumchar(setup->key);
			str[++c[0]] = '\0';
		}
	}
	if (setup->key == ENTER && *str >= 1)
		*flag = 1;
	return (OK);
}

static int		ft_dim_input(t_setup *setup, size_t w_flag)
{
	if (!MAP->dim_t[w_flag])
	{
		if (ft_map_dim(setup, &MAP->dim_i[w_flag], MAP->dim[w_flag], \
					&MAP->dim_t[w_flag]) == ERROR)
			return (ERROR);
		if (MAP->dim_t[w_flag])
		{
			MAP->mapsize[w_flag] = ft_atoi(MAP->dim[w_flag]);
			if (MAP->mapsize[w_flag] < M_MIN_SIZE || MAP->mapsize[w_flag] >\
					M_MAX_SIZE)
				return (ERROR);
		}
	}
	return (OK);
}

int				ft_configure_dim(t_setup *setup)
{
	size_t		w_flag;
	static int	dim_col[2];

	w_flag = MAP->dim_t[0];
	if (ft_dim_input(setup, w_flag) == ERROR)
		return (ERROR);
	dim_col[w_flag] = (MAP->dim_t[w_flag] == 1) ? 65280 : 16711680;
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 6, dim_col[0], "WIDTH  : ");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 10, \
			SETUP.height / 6, dim_col[0], MAP->dim[0]);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 4, dim_col[1], "HEIGHT : ");
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 10, \
			SETUP.height / 4, dim_col[1], MAP->dim[1]);
	return (OK);
}

size_t			ft_name_input(t_setup *setup)
{
	if (FD->name == NULL)
	{
		if (!(FD->name = ft_strnew(666)))
			return (ERROR);
	}
	if (SETUP.key != ENTER && MAP->yes_t && ft_mlx_printkeytochar(SETUP.key))
		FD->name[MAP->name_i++] = ft_mlx_printkeytochar(SETUP.key);
	return (OK);
}
