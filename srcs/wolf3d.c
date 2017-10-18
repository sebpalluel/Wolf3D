/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/18 14:24:09 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				usage(int mode)
{
	if (mode == OK)
		ft_putendl("program exited normally");
	else if (mode == ERROR)
	{
		ft_putendl("usage: ./wolf3d map_name");
		ft_putendl("or to activate map_generator mode, enter : ./wolf3d");
	}
	if (mode == MAP_ERROR)
		ft_putendl(MAP_ERROR_S);
	else if (mode == DIM_ERROR)
		ft_putendl(DIM_ERROR_S);
	else if (mode == FILE_ERROR)
		ft_putendl(FILE_ERROR_S);
	return (mode);
}

int				main(int ac, char **av)
{
	t_setup		*setup;

	if (!(setup = (t_setup *)malloc(sizeof(t_setup) * (NUM_THREAD + 1))))
		return (-1);
	ft_memset(setup, 0, sizeof(t_setup));
	setup->mode = STATE_START;
	setup->ac = ac;
	setup->args = av;
	setup->midalpha = (int)ft_stoul("c0000000", 16);
	setup->alpha = (int)ft_stoul("0A000000", 16);
	if ((setup->error = (ac < 3) ? OK : ERROR) == OK \
			&& ft_setup_mode(setup, 1) == OK)
		ft_mlx_process(setup);
	return (ft_setup_mode(setup, 0));
}
