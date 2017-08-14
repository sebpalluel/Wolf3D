/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/14 19:06:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				ft_error_usage()
{
//	ft_putendl("Usage:\n\
//			./fractol \"mandelbrot\"\n\
//			./fractol \"julia\"\n\
//			./fractol \"burningship\"\n\
//			./fractol \"cantor\"\n\
//			./fractol \"all\"");
	return (0);
}

int				main(int ac, char **av)
{
	t_setup	*setup = NULL;

	if (ac == 2)
	{
		setup = (t_setup *)malloc(sizeof(t_setup) * (NUM_THREAD + 1));
		if (!setup)
			return (-1);
		ft_bzero(setup, sizeof(t_setup) * (NUM_THREAD + 1));
		if (ft_setup_mode(setup, 1) != OK && \
				ft_setup_fract_select(av, setup) != OK && \
				SETUP.f_mode != 666)
		ft_mlx_process(setup);
		return (ft_setup_mode(setup, 0));
	}
	return (ft_error_usage());
}
