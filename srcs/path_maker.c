/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:17:31 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/23 15:19:19 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		ft_godown(t_setup *setup)
{
	PATH.to_find.y++;;
	if (MAP->tmp_map[PATH.to_find.y][PATH.to_find.x])
	{
		PATH.is_full = IS_FULL;
		MAP->tmp_map[PATH.to_find.y][PATH.to_find.x] = 0;
	}
}

static void		ft_goleft(t_setup *setup)
{
	if (PATH.to_find.x - 1 != PATH.pos.x)
	{
		PATH.to_find.x--;
		if (MAP->tmp_map[PATH.to_find.y][PATH.to_find.x])
		{
			MAP->tmp_map[PATH.to_find.y][PATH.to_find.x] = 0;
			PATH.is_full = IS_FULL;
		}
	}
	PATH.lr[0] = 1;
}

static void		ft_goright(t_setup *setup)
{
	if (PATH.to_find.x + 1 != PATH.pos.x)
	{
		PATH.to_find.x++;
		if (MAP->tmp_map[PATH.to_find.y][PATH.to_find.x])
		{
			MAP->tmp_map[PATH.to_find.y][PATH.to_find.x] = 0;
			PATH.is_full = IS_FULL;
		}
	}
	PATH.lr[1] = 1;
}

static void		ft_emptyneighbors(t_setup *setup, size_t rand_dir)
{
	if (rand_dir == GO_DOWN)
		ft_godown(setup);
	else if (rand_dir == GO_lEFT)
		ft_goleft(setup);
	else if (rand_dir == GO_RIGHT)
		ft_goright(setup);
}

size_t			ft_path_maker(t_setup *setup)
{
	size_t		rand_dir;

	ft_pixcpy(&PATH.pos, &PATH.to_find);
	PATH.lr[0] = 0;
	PATH.lr[1] = 0;
	PATH.is_full = 1;
	while (PATH.is_full != IS_FULL && PATH.to_find.y < M_HEIGHT - 2)
	{
		if (PATH.lr[0] && PATH.lr[1])
			rand_dir = GO_DOWN;
		else if (PATH.to_find.x > 1 && PATH.to_find.x < M_WIDTH - 2 && \
				PATH.to_find.y < M_HEIGHT - 2)
			rand_dir = ft_random(0, 2, 1);
		else if (PATH.to_find.x <= 1 && PATH.lr[1] != 1)
			rand_dir = GO_RIGHT;
		else if (PATH.to_find.x >= M_WIDTH - 2 && PATH.lr[0] != 1)
			rand_dir = GO_lEFT;
		ft_emptyneighbors(setup, rand_dir);
	}
	ft_pixcpy(&PATH.to_find, &PATH.pos);
	if (PATH.to_find.y == M_HEIGHT - 2)
		return (OK);
	return (ERROR);
}
