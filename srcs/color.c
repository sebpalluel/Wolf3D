/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 13:41:00 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/24 16:09:10 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				ft_give_color(t_setup *setup, t_color *color, int alpha)
{
	if (MAP->drunk_mode)
		return (alpha + ft_colortohex(color));
	else
		return (ft_colortohex(color));
}

int				ft_select_color(t_setup *setup)
{
	if (RAY->side)
	{
		if (RAY->dir.y > 0)
			return (ft_give_color(setup, &MAP->west, setup->midalpha));
		else
			return (ft_give_color(setup, &MAP->east, setup->midalpha));
	}
	else if (!RAY->side)
	{
		if (RAY->dir.x > 0)
			return (ft_give_color(setup, &MAP->south, setup->midalpha));
		else
			return (ft_give_color(setup, &MAP->north, setup->midalpha));
	}
	return (ft_give_color(setup, &MAP->ground, setup->alpha));
}
