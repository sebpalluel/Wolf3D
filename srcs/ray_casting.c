/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:56:37 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/25 18:21:33 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static int		ft_ray_cast(t_setup *setup)
{
	if (RAY->sidedist.x < RAY->sidedist.y)
	{
		RAY->sidedist.x += RAY->deltadist.x;
		RAY->map.x += (int)RAY->step.x;
		RAY->side = 0;
	}
	else
	{
		RAY->sidedist.y += RAY->deltadist.y;
		RAY->map.y += (int)RAY->step.y;
		RAY->side = 1;
	}
	if (MAP->map[RAY->map.y][RAY->map.x] == WALL)
		RAY->hit = 1;
	if ((RAY->map.y >= M_HEIGHT - 1 || RAY->map.x >= M_WIDTH - 1) && !RAY->hit)
		return (ERROR);
	return (OK);
}

static void		ft_ray_dir(t_setup *setup)
{
	if (RAY->dir.x < 0.)
	{
		RAY->step.x = -1;
		RAY->sidedist.x = (PLAY->pos.x - (double)RAY->map.x) * RAY->deltadist.x;
	}
	else
	{
		RAY->step.x = 1;
		RAY->sidedist.x = ((double)RAY->map.x + 1 - PLAY->pos.x) * \
						RAY->deltadist.x;
	}
	if (RAY->dir.y < 0.)
	{
		RAY->step.y = -1;
		RAY->sidedist.y = (PLAY->pos.y - (double)RAY->map.y) * RAY->deltadist.y;
	}
	else
	{
		RAY->step.y = 1;
		RAY->sidedist.y = ((double)RAY->map.y + 1 - PLAY->pos.y) * \
						RAY->deltadist.y;
	}
	RAY->hit = 0;
}

static void		ft_ray_casting_init(t_setup *setup, double angle_inc)
{
	RAY->dir.x = PLAY->dir.x + PLAY->plane.x * angle_inc;
	RAY->dir.y = PLAY->dir.y + PLAY->plane.y * angle_inc;
	RAY->deltadist.x = sqrt(1 + (pow(RAY->dir.y, 2) / pow(RAY->dir.x, 2)));
	RAY->deltadist.y = sqrt(1 + (pow(RAY->dir.x, 2) / pow(RAY->dir.y, 2)));
	RAY->map.x = (int)PLAY->pos.x;
	RAY->map.y = (int)PLAY->pos.y;
}

static double	ft_ray_size(t_setup *setup)
{
	double ret;

	if (!RAY->side)
		ret = (RAY->map.x - PLAY->pos.x + (1 - RAY->step.x) / 2.) / RAY->dir.x;
	else
		ret = (RAY->map.y - PLAY->pos.y + (1 - RAY->step.y) / 2.) / RAY->dir.y;
	return (ret);
}

size_t			ft_ray_casting(t_setup *setup)
{
	int			posx;
	double		angle_inc;
	int			lineheight;

	posx = -1;
	while (++posx < (int)S_WIDTH)
	{
		angle_inc = 2 * (double)posx / (double)S_WIDTH - 1;
		ft_ray_casting_init(setup, angle_inc);
		ft_ray_dir(setup);
		while (!(RAY->hit))
			if (ft_ray_cast(setup) == ERROR)
				return (ERROR);
		RAY->size = ft_ray_size(setup);
		lineheight = S_HEIGHT / RAY->size;
		ft_draw_vert_line(setup, posx, lineheight);
	}
	return (OK);
}
