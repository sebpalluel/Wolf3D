/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   configure_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:20:22 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/30 22:03:51 by psebasti         ###   ########.fr       */
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

int				ft_configure_dim(t_setup *setup)
{
	size_t		w_flag;
	static int	dim_col[2];

	w_flag = MAP->dim_t[0];
	if (!MAP->dim_t[w_flag])
	{
		ft_map_dim(setup, &MAP->dim_i[w_flag], MAP->dim[w_flag], \
				&MAP->dim_t[w_flag]);
		MAP->mapsize[w_flag] = ft_atoi(MAP->dim[w_flag]);
		if (MAP->mapsize[w_flag] < M_MIN_HEIGHT || MAP->mapsize[w_flag] >\
				M_MAX_HEIGHT)
			return (ERROR);
	}
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

size_t		ft_name_input(t_setup *setup)
{
	char		*tmp;

	if (FD->name == NULL)
		if (!(FD->name = ft_strnew(1)))
			return (ERROR);
	if (SETUP.key != ENTER && MAP->yes_t && ft_mlx_printkeytochar(SETUP.key))
	{
		if (!(tmp = ft_strdup(FD->name)))
			return (ERROR);
		free(FD->name);
		if (!(FD->name = ft_strnew(MAP->name_i + 1)))
			return (ERROR);
		FD->name = tmp;
		FD->name[MAP->name_i] = ft_mlx_printkeytochar(SETUP.key);
		FD->name[++MAP->name_i] = '\0';
	}
	return (OK);
}
