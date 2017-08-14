/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 20:55:22 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/02 18:01:59 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	ft_zoom(int x, int y, t_fract *fract)
{
	fract->focus.x = x;
	fract->focus.y = y;
	fract->vec.x = (x / fract->zoom + fract->vec.x) - ((fract->zoom * AMP) / 2);
	fract->vec.x += ((fract->zoom * AMP) / 2) - (x / (fract->zoom * AMP));
	fract->vec.y = (y / fract->zoom + fract->vec.y) - ((fract->zoom * AMP) / 2);
	fract->vec.y += ((fract->zoom * AMP) / 2) - (y / (fract->zoom * AMP));
	fract->zoom *= AMP;
	fract->it_max++;
}

static void	ft_dezoom(t_fract *fract)
{
	fract->vec.x = (fract->focus.x / fract->zoom + fract->vec.x) -\
				   ((fract->zoom / AMP) / 2);
	fract->vec.x += ((fract->zoom / AMP) / 2) - (fract->focus.x /\
			(fract->zoom / AMP));
	fract->vec.y = (fract->focus.y / fract->zoom + fract->vec.y) -\
				   ((fract->zoom / AMP) / 2);
	fract->vec.y += ((fract->zoom / AMP) / 2) - (fract->focus.y /\
			(fract->zoom / AMP));
	fract->zoom /= AMP;
	fract->it_max--;
}

int			ft_mouse_moove(int x, int y, t_setup *setup)
{
	JUL->c_r = -0.285 + (double)x / 2;
	JUL->c_i = -0.02 + (double)y / 2;
	ft_expose_hook(setup);
	return (1);
}

int			ft_mouse_hook(int mousecode, int x, int y, t_setup *setup)
{
	int		frac;

	frac = -1;
	if (SETUP.f_mode < 3)
	{
		if (mousecode == WHEEL_UP || mousecode == MOUSE_LEFT)
			ft_zoom(x, y, SETUP.fract[SETUP.f_mode]);
		else if (mousecode == WHEEL_DOWN || mousecode == MOUSE_RIGHT)
			ft_dezoom(SETUP.fract[SETUP.f_mode]);
	}
	else
	{
		if (mousecode == WHEEL_UP || mousecode == MOUSE_LEFT)
			while (++frac < FNUM - 1)
				ft_zoom(x, y, SETUP.fract[frac]);
		else if (mousecode == WHEEL_DOWN || mousecode == MOUSE_RIGHT)
			while (++frac < FNUM - 1)
				ft_dezoom(SETUP.fract[frac]);
	}
	ft_expose_hook(setup);
	return (1);
}
