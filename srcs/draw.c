/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 22:17:13 by psebasti          #+#    #+#             */
/*   Updated: 2017/09/09 17:57:00 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			ft_put_pixel(t_setup *setup, int x, int y, int color)
{
	int			*tmp;

	if (y >= (int)S_HEIGHT || x >= (int)S_WIDTH || x < 0 || y < 0)
		return ;
	tmp = (int *)&IMG->image_addr[(y * IMG->size_x) + (x * (IMG->bbp / 8))];
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
	if (MAP->cheat && MAP->map[j][i] == 2)
		ft_draw_map_coord(setup, pos.x, pos.y, 0x00FF00);
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
