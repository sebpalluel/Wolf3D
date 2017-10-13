/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 22:17:13 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/11 14:21:30 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			ft_put_pixel(t_setup *setup, int x, int y, int color)
{
	int			*tmp;
	size_t		index;

	if (y >= (int)setup->height || x >= (int)setup->width || x < 0 || y < 0)
		return ;
	index = (y * setup->width) * (IMG->bbp >> 3) \
			+ x * (IMG->bbp >> 3);
	tmp = (int *)&IMG->image_addr[index];
	*tmp = color;
}

static void		ft_draw_map_coord(t_setup *setup, int x, int y, int color)
{
	int			i;
	int			j;

	i = -1;
	while (++i <= MAP->draw_tick)
	{
		j = -1;
		while (++j <= MAP->draw_tick)
			ft_put_pixel(setup, x + i, y + j, color);
	}
}

static void		ft_select_map_coord(t_setup *setup, int i, int j)
{
	t_pix		pos;

	pos.x = i + (MAP->draw_tick * (i + 1));
	pos.y = j + (MAP->draw_tick * (j + 1));
	if (MAP->map[j][i] == 1)
		ft_draw_map_coord(setup, pos.x, pos.y, 0x0000FF);
	if (MAP->map[j][i] == 2)
	{
		if (MAP->cheat)
			ft_draw_map_coord(setup, pos.x, pos.y, 0x00FF00);
		else
			ft_draw_map_coord(setup, pos.x, pos.y, 0xFFFFFF);
	}
	if ((int)PLAY->pos.x == i && (int)PLAY->pos.y == j)
		ft_draw_map_coord(setup, pos.x, pos.y, 0xFF0000);
	else if (MAP->map[j][i] == 0)
		ft_draw_map_coord(setup, pos.x, pos.y, 0xFFFFFF);
}

void			ft_draw_map(t_setup *setup)
{
	int			i;
	int			j;

	MAP->draw_tick = ((M_WIDTH >= M_HEIGHT) ? ((float)M_MAX_SIZE * (1. / \
					(float)M_WIDTH)) : ((float)M_MAX_SIZE * (1. / \
						(float)M_HEIGHT)));
	i = -1;
	while (++i < M_WIDTH)
	{
		j = -1;
		while (++j < M_HEIGHT)
			ft_select_map_coord(setup, i, j);
	}
}
