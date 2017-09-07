/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:06:31 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/07 21:28:43 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_pos_player(t_setup *setup)
{
	t_vec3	pos;

	ft_memset(&pos, 0, sizeof(t_vec3));
	while (MAP->map[(int)pos.y][(int)pos.x] != PATH_)
	{
		pos.x = ft_random(1, M_HEIGHT - 1, 1);
		pos.y = ft_random(1, M_WIDTH - 1, 1);
	}
	ft_vec3cpy(&pos, &PLAY->pos);
	ft_vec3populate(&PLAY->dir, -1., 0., 0.0);
	ft_vec3populate(&PLAY->plane, 0., 0.66, 0.0);
	PLAY->randpos = 1;
}
