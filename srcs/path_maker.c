/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:17:31 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/25 16:10:13 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	ft_path_maker_down(t_setup *setup)
{
	ft_pixcpy(&PATH.pos, &PATH.to_find);
	PATH.lrdu[0] = 0;
	PATH.lrdu[1] = 0;
	PATH.is_full = 1;
	PATH.rand_dir = 666;
	while (PATH.is_full != IS_FULL && PATH.to_find.y < M_HEIGHT - 2)
	{
		if (PATH.lrdu[0] && PATH.lrdu[1])
			PATH.rand_dir = GO_DOWN;
		else if (PATH.to_find.x > 1 && PATH.to_find.x < M_WIDTH - 2)
			PATH.rand_dir = ft_random(0, 2, 1);
		else if (PATH.to_find.x > 1 && PATH.lrdu[0] != 1)
			PATH.rand_dir = GO_lEFT;
		else if (PATH.to_find.x < M_WIDTH - 2 && PATH.lrdu[1] != 1)
			PATH.rand_dir = GO_RIGHT;
		else if (PATH.rand_dir == 666)
			PATH.rand_dir = GO_DOWN;
		ft_path_maker_dir(setup);
	}
	ft_pixcpy(&PATH.to_find, &PATH.pos);
	if (PATH.to_find.y == M_HEIGHT - 2)
		return (OK);
	return (ERROR);
}

static size_t	ft_path_maker_right(t_setup *setup)
{
	ft_pixcpy(&PATH.pos, &PATH.to_find);
	PATH.lrdu[2] = 0;
	PATH.lrdu[3] = 0;
	PATH.is_full = 1;
	PATH.rand_dir = 666;
	while (PATH.is_full != IS_FULL && PATH.to_find.x < M_WIDTH - 2)
	{
		if (PATH.lrdu[2] && PATH.lrdu[3])
			PATH.rand_dir = GO_RIGHT;
		else if (PATH.to_find.y < M_HEIGHT - 2 && PATH.to_find.x < M_WIDTH - 2)
			PATH.rand_dir = (ft_random(0, 1, 1) == 1) ? GO_RIGHT : GO_DOWN;
		else if (PATH.to_find.y > 1 && PATH.lrdu[3] != 1)
			PATH.rand_dir = GO_UP;
		else if (PATH.to_find.y < M_HEIGHT - 2 && PATH.lrdu[2] != 1)
			PATH.rand_dir = GO_DOWN;
		else if (PATH.rand_dir == 666)
			PATH.rand_dir = GO_RIGHT;
		ft_path_maker_dir(setup);
	}
	ft_pixcpy(&PATH.to_find, &PATH.pos);
	if (PATH.to_find.x == M_WIDTH - 2)
		return (OK);
	return (ERROR);
}

static void		ft_path_down_or_right(t_setup *setup, size_t mode)
{
	if (!mode)
	{
		PATH.pos.x = ft_random(1, M_WIDTH - 2, 1);
		PATH.pos.y = 1;
		while (ft_path_maker_down(setup) != OK)
			;
	}
	else
	{
		PATH.pos.y = ft_random(1, M_HEIGHT - 2, 1);
		PATH.pos.x = 1;
		while (ft_path_maker_right(setup) != OK)
			;
	}
}

void			ft_path_maker(t_setup *setup)
{
	if (M_HEIGHT > M_WIDTH)
		ft_path_down_or_right(setup, 0);
	if (M_HEIGHT < M_WIDTH)
		ft_path_down_or_right(setup, 1);
	if (M_HEIGHT == M_WIDTH)
	{
		ft_path_down_or_right(setup, 0);
		ft_path_down_or_right(setup, 1);
	}
}
