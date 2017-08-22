/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:58:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/22 18:23:14 by psebasti         ###   ########.fr       */
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

static int		ft_configure_dim(t_setup *setup)
{
	size_t		w_flag;
	static int	dim_col[2];

	w_flag = MAP->dim_t[0];
	if (!MAP->dim_t[w_flag])
	{
		ft_map_dim(setup, &MAP->dim_i[w_flag], MAP->dim[w_flag], \
				&MAP->dim_t[w_flag]);
		MAP->mapsize[w_flag] = ft_atoi(MAP->dim[w_flag]);
		if (MAP->mapsize[w_flag] < 2)
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

static void		ft_random_map(t_setup *setup)
{
	int	width[2];
	int	height;
	int	rand_num;

	height = -1;
	while (++height < M_WIDTH)
	{
		width[0] = -1;
		width[1] = 0;
		while (++width[0] < M_HEIGHT)
		{
			rand_num = ft_random(0, MAX_ELEM, 1);
			MAP->tmp_map[height][width[0]] = (size_t)rand_num;
			MAP->map_str[height][width[1]] = *ft_itoa(rand_num);
			width[1]++;
			MAP->map_str[height][width[1]] = ' ';
			width[1]++;
		}
			MAP->map_str[height][width[1]] = '\n';
	}
}

static size_t	ft_generate_map(t_setup *setup)
{
	MAP->map_str = ft_tabnewstr(M_WIDTH * 2, M_HEIGHT);
	MAP->tmp_map = ft_tabnewsize_t(M_WIDTH, M_HEIGHT);
	if (&MAP->tmp_map[0] != NULL && &MAP->tmp_map[0][0] != NULL)
		ft_random_map(setup);
	ft_printintarray((int **)MAP->tmp_map, M_WIDTH, M_HEIGHT);
	SETUP.mode = STATE_SAVE;
	return (OK);
}

static size_t	ft_name_input(t_setup *setup)
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

static size_t	ft_write_to_file(t_setup *setup)
{
	int			err;
	size_t		line;

	err = 0;
	line = 0;
	ft_open(FD->path, FD->name, O_WRONLY, O_APPEND);
	while (line < (size_t)M_HEIGHT)
	{
		if (FD->fd > 0)
		{
			while ((err = write(FD->fd, MAP->map_str[line], M_WIDTH)) > 0)
				;
			if (err < 0)
				return (ERROR);
			line++;
		}
	}
	if (FD->fd < 0 && err != 0)
		return (ERROR);
	else
	{
		SETUP.mode = STATE_RUN;
		return (OK);
	}
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

	if (SETUP.key != Y_KEY && SETUP.key != N_KEY && !MAP->yes_t)
		yn_col = 10066431;
	else
	{
		if (SETUP.key == Y_KEY || MAP->yes_t)
		{
			ft_save_file(setup);
			MAP->yes_t = 1;
		}
		yn_col = (MAP->yes_t == 1) ? 65280 : 16711680;
	}
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 3.3, 0x00611DE9, SAVE_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 3, yn_col, YESORNO_STR);
	return (OK);
}

int				ft_setup_menu(t_setup *setup)
{
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 50, 0x00611DE9, MAPG_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 8, 0x009999FF, WIDTHG_STR);
	mlx_string_put(MLX->mlx_ptr, MLX->win_ptr, SETUP.width / 50, \
			SETUP.height / 5, 0x009999FF, HEIGHTG_STR);
	if (ft_configure_dim(setup) == OK && MAP->dim_t[1] && \
			ft_generate_map(setup) == OK)
		return (OK);
	return (ERROR);
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
		FD = (t_fd *)ft_memalloc(sizeof(t_fd));
		MAP->dim_t[0] = 0;
		MAP->dim_t[1] = 0;
		MAP->dim_i[0] = 0;
		MAP->dim_i[1] = 0;
		MAP->yes_t = 0;
		MAP->name_t = 0;
		MAP->name_i = 0;
		if (MLX == NULL || IMG == NULL || MAP == NULL || FD == NULL)
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
