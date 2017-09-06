/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:28:41 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/01 19:10:35 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	ft_write_to_file(t_setup *setup)
{
	int			err;
	size_t		line;

	err = 0;
	line = 0;
	if (ft_open(FD, O_WRONLY, O_APPEND) != OK)
		return (ERROR);
	while (line < (size_t)M_HEIGHT)
	{
			err = write(FD->fd, MAP->map_str[line], M_WIDTH * 2 + 1);
			if (err < 0)
				return (ERROR);
			line++;
	}
		SETUP.mode = STATE_RUN;
		return (OK);
}

static size_t	ft_save_file(t_setup *setup)
{
	int			name_col;

	name_col = (MAP->name_t == 1) ? 65280 : 16711680;
	if (ft_name_input(setup) != OK)
		return (ERROR);
	if (setup->key == ENTER && *FD->name > 1)
	{
		if (!(FD->path = ft_strdup("maps/")))
			return (ERROR);
		ft_create_file(FD, 777);
		MAP->name_t = 1;
	}
	name_col = (MAP->name_t == 1) ? 65280 : 16711680;
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 2.7, 0x00611DE9, NAME_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 2.5, name_col, FD->name);
	if (MAP->name_t && ft_write_to_file(setup) == OK)
		return (OK);
	else
		return (ERROR);
}

int				ft_save_map(t_setup *setup)
{
	int			yn_col;
	size_t		ret;

	ret = ERROR;
	if (SETUP.key != Y_KEY && SETUP.key != N_KEY && !MAP->yes_t)
		yn_col = 10066431;
	else
	{
		if (SETUP.key == Y_KEY || MAP->yes_t)
		{
			ret = ft_save_file(setup);
			MAP->yes_t = 1;
		}
		else if (SETUP.key == N_KEY)
			ret = OK;
		yn_col = (MAP->yes_t == 1) ? 65280 : 16711680;
	}
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 3.3, 0x00611DE9, SAVE_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 3, yn_col, YESORNO_STR);
	return (ret);
}
