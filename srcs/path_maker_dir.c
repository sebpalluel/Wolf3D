/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_maker_dir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:52:43 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/03 16:57:45 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void	ft_godown(t_setup *setup)
{
	if (PATH.to_find.y + 1 != PATH.pos.y)
	{
		PATH.to_find.y++;;
		if (MAP->map[PATH.to_find.y][PATH.to_find.x] == WALL)
		{
			PATH.is_full = IS_FULL;
			MAP->map[PATH.to_find.y][PATH.to_find.x] = PATH_;
		}
	}
	PATH.lrdu[2] = 1;
}

static void	ft_goup(t_setup *setup)
{
	if (PATH.to_find.y - 1 != PATH.pos.y)
	{
		PATH.to_find.y--;;
		if (MAP->map[PATH.to_find.y][PATH.to_find.x] == WALL)
		{
			PATH.is_full = IS_FULL;
			MAP->map[PATH.to_find.y][PATH.to_find.x] = PATH_;
		}
	}
	PATH.lrdu[3] = 1;
}

static void	ft_goleft(t_setup *setup)
{
	if (PATH.to_find.x - 1 != PATH.pos.x)
	{
		PATH.to_find.x--;
		if (MAP->map[PATH.to_find.y][PATH.to_find.x] == WALL)
		{
			MAP->map[PATH.to_find.y][PATH.to_find.x] = PATH_;
			PATH.is_full = IS_FULL;
		}
	}
	PATH.lrdu[0] = 1;
}

static void	ft_goright(t_setup *setup)
{
	if (PATH.to_find.x + 1 != PATH.pos.x)
	{
		PATH.to_find.x++;
		if (MAP->map[PATH.to_find.y][PATH.to_find.x] == WALL)
		{
			MAP->map[PATH.to_find.y][PATH.to_find.x] = PATH_;
			PATH.is_full = IS_FULL;
		}
	}
	PATH.lrdu[1] = 1;
}

void		ft_path_maker_dir(t_setup *setup)
{
	if (PATH.rand_dir == GO_DOWN)
		ft_godown(setup);
	else if (PATH.rand_dir == GO_UP)
		ft_goup(setup);
	else if (PATH.rand_dir == GO_lEFT)
		ft_goleft(setup);
	else if (PATH.rand_dir == GO_RIGHT)
		ft_goright(setup);
}
