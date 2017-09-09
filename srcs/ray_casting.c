/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/07 18:56:37 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/09 13:56:08 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static	t_color		*ft_select_color(t_setup *setup)
{
	if (RAY->side)
	{
		if (RAY->dir.y > 0)
			return (&MAP->west);
		else
			return (&MAP->east);
	}
	else if (!RAY->side)
	{
		if (RAY->dir.x > 0)
			return (&MAP->south);
		else
			return (&MAP->north);
	}
	return (&MAP->ground);
}

void			ft_draw_vert_line(t_setup *setup, int x, int len)
{
	int	i;
	int start;
	int end;

	start = -len / 2 + S_HEIGHT / 2;
	end = len / 2 + S_HEIGHT / 2;
	i = 0;
	if (start < 0)
		start = 0;
	if (end >= (int)S_HEIGHT)
		end = S_HEIGHT - 1;
	while (++i < start)
		ft_put_pixel(setup, x, i, ft_colortohex(&MAP->sky));
	i--;
	while (++i < end)
		ft_put_pixel(setup, x, i, ft_colortohex(ft_select_color(setup)));
	i--;
	while (++i < (int)S_HEIGHT)
		ft_put_pixel(setup, x, i, ft_colortohex(&MAP->ground));
}

static void		ft_ray_touch(t_setup *setup)
{
	if (RAY->sdist.x < RAY->sdist.y)
	{
		RAY->sdist.x += RAY->ddist.x;
		RAY->map.x += (int)RAY->step.x;
		RAY->side = 0;
	}
	else
	{
		RAY->sdist.y += RAY->ddist.y;
		RAY->map.y += (int)RAY->step.y;
		RAY->side = 1;
	}
	//printf("max width %d, max height %d, map.x %d, map.y %d\n", M_WIDTH, \
	//		M_HEIGHT, RAY->map.x, RAY->map.y);
	if (MAP->map[RAY->map.y][RAY->map.x] == WALL)
		RAY->touch = 1;
}

static void		ft_ray_dir(t_setup *setup)
{
	if (RAY->dir.x < 0)
	{
		RAY->step.x = -1;
		RAY->sdist.x = (RAY->pos.x - (double)RAY->map.x) * RAY->ddist.x;
	}
	else
	{
		RAY->step.x = 1;
		RAY->sdist.x = ((double)RAY->map.x + 1 - RAY->pos.x) * RAY->ddist.x;
	}
	if (RAY->dir.y < 0)
	{
		RAY->step.y = -1;
		RAY->sdist.y = (RAY->pos.y - (double)RAY->map.y) * RAY->ddist.y;
	}
	else
	{
		RAY->step.y = 1;
		RAY->sdist.y = ((double)RAY->map.y + 1 - RAY->pos.y) * RAY->ddist.y;
	}
	RAY->touch = 0;
}

size_t			ft_ray_casting(t_setup *setup)
{
	int			x;
	double		xi;

	x = -1;
	while (++x < (int)S_WIDTH)
	{
		xi = 2 * (double)x / (double)S_WIDTH - 1;
		ft_vec3cpy(&PLAY->pos, &RAY->pos);
		RAY->dir.x = PLAY->dir.x + PLAY->plane.x * xi;
		RAY->dir.y = PLAY->dir.y + PLAY->plane.y * xi;
		RAY->ddist.x = sqrt(1 + (pow(RAY->dir.y, 2) / pow(RAY->dir.x, 2)));
		RAY->ddist.y = sqrt(1 + (pow(RAY->dir.x, 2) / pow(RAY->dir.y, 2)));
		RAY->map.x = (int)RAY->pos.x;
		RAY->map.y = (int)RAY->pos.y;
		ft_ray_dir(setup);
		while (!(RAY->touch))
			ft_ray_touch(setup);
		if (!RAY->side)
			RAY->size = (RAY->map.x - RAY->pos.x + (1 - RAY->step.x) / 2) / RAY->dir.x;
		else
			RAY->size = (RAY->map.y - RAY->pos.y + (1 - RAY->step.y) / 2) / RAY->dir.y;
		ft_draw_vert_line(setup, x, (int)((S_HEIGHT / RAY->size)));
	}
	return (OK);
}

