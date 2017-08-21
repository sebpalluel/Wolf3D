/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 20:09:10 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/21 16:48:43 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				main(int ac, char **av)
{
	t_setup	*setup = NULL;

	setup = (t_setup *)malloc(sizeof(t_setup) * (NUM_THREAD + 1));
	if (!setup)
		return (-1);
	ft_bzero(setup, sizeof(t_setup) * (NUM_THREAD + 1));
	setup->mode = STATE_START;
	setup->ac = ac;
	setup->args = av;
	if (ft_setup_mode(setup, 1) == OK)
		ft_mlx_process(setup);
	return (ft_setup_mode(setup, 0));
}