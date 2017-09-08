/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 20:06:31 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/08 19:59:03 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	ft_test_move(t_setup *setup)
{
	t_pix		pos;

	if (SETUP.udlr[0])
	{
		pos.x = PLAY->pos.x + MOVE_STEP * PLAY->dir.x;
		pos.y = PLAY->pos.y + MOVE_STEP * PLAY->dir.y;
	}
	if (SETUP.udlr[1])
	{
		pos.x = PLAY->pos.x - MOVE_STEP * PLAY->dir.x;
		pos.y = PLAY->pos.y - MOVE_STEP * PLAY->dir.y;
	}
	if (pos.x < M_WIDTH && pos.y < M_HEIGHT && pos.x > 0 && pos.y > 0
			&& MAP->map[pos.y][pos.x] != WALL)
		return (OK);
	return (ERROR);
}

static void		ft_turn_player(t_setup *setup, double prev_dirx, \
		double prev_planex)
{
	if (SETUP.udlr[2])
	{
		PLAY->dir.x = prev_dirx * cos(ROT_STEP)
			- PLAY->dir.y * sin(ROT_STEP);
		PLAY->dir.y = prev_dirx * sin(ROT_STEP)
			+ PLAY->dir.y * cos(ROT_STEP);
		PLAY->plane.x = prev_planex * cos(ROT_STEP)
			- PLAY->plane.y * sin(ROT_STEP);
		PLAY->plane.y = prev_planex * sin(ROT_STEP)
			+ PLAY->plane.y * cos(ROT_STEP);
	}
	if (SETUP.udlr[3])
	{
		PLAY->dir.x = prev_dirx * cos(-ROT_STEP)
			- PLAY->dir.y * sin(-ROT_STEP);
		PLAY->dir.y = prev_dirx * sin(-ROT_STEP)
			+ PLAY->dir.y * cos(-ROT_STEP);
		PLAY->plane.x = prev_planex * cos(-ROT_STEP)
			- PLAY->plane.y * sin(-ROT_STEP);
		PLAY->plane.y = prev_planex * sin(-ROT_STEP)
			+ PLAY->plane.y * cos(-ROT_STEP);
	}
}

static void		ft_move_player(t_setup *setup)
{
	if (SETUP.key == UP && ft_test_move(setup) == OK)
	{
		PLAY->pos.x += MOVE_STEP * PLAY->dir.x;
		PLAY->pos.y += MOVE_STEP * PLAY->dir.y;
	}
	else if (SETUP.key == DOWN && ft_test_move(setup) == OK)
	{
		PLAY->pos.x -= MOVE_STEP * PLAY->dir.x;
		PLAY->pos.y -= MOVE_STEP * PLAY->dir.y;
	}
	ft_turn_player(setup, PLAY->dir.x, PLAY->plane.x);
}

void			ft_pos_player(t_setup *setup)
{
	t_vec3		pos;

	if (!PLAY->randpos)
	{
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
	ft_move_player(setup);
}
