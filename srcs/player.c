/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:06:31 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/07 20:59:49 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		ft_pos_player(t_setup *setup)
{
	t_pix	pos;

	ft_memset(&pos, 0, sizeof(t_pix));
	if (!PLAY->randpos)
	{
		while (MAP->map[pos.y][pos.x] != PATH_)
		{
			pos.x = ft_random(1, M_HEIGHT - 1, 1);
			pos.y = ft_random(1, M_WIDTH - 1, 1);
		}
		ft_pixcpy(&pos, &PLAY->pos);
		PLAY->randpos = 1;
	}
}
