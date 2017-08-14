/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:50:09 by psebasti          #+#    #+#             */
/*   Updated: 2017/07/29 16:25:32 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int		ft_pthread_process(t_setup *setup, void *(*f)(void *))
{
	pthread_t	thread[NUM_THREAD];
	int			i;
	int			err;

	i = 0;
	err = 0;
	while (i < NUM_THREAD)
	{
		if ((err = pthread_create(&thread[i], NULL, f, &setup[i + 1])) != 0)
			return (err);
		i++;
	}
	while (i > 0)
	{
		i--;
		if ((err = pthread_join(thread[i], NULL)) != 0)
			return (err);
	}
	return (err);
}

static void		ft_fractol_cpy(t_setup *setup, size_t frac, size_t i)
{
	size_t		j;

	setup[i + 1].fract[frac]->it_max = SETUP.fract[frac]->it_max;
	setup[i + 1].fract[frac]->zoom = SETUP.fract[frac]->zoom;
	setup[i + 1].fract[frac]->c_r = SETUP.fract[frac]->c_r;
	setup[i + 1].fract[frac]->c_i = SETUP.fract[frac]->c_i;
	setup[i + 1].fract[frac]->z_i = SETUP.fract[frac]->z_i;
	setup[i + 1].fract[frac]->z_r = SETUP.fract[frac]->z_r;
	ft_vec3cpy(&SETUP.fract[frac]->pos, &setup[i + 1].fract[frac]->pos);
	ft_vec3cpy(&SETUP.fract[frac]->vec, &setup[i + 1].fract[frac]->vec);
	ft_vec3cpy(&SETUP.fract[frac]->focus, &setup[i + 1].fract[frac]->focus);
	j = 0;
	while (j < 3)
	{	
		ft_colorcpy(SETUP.fract[frac]->clr[j], \
				setup[i + 1].fract[frac]->clr[j]);
		j++;
	}
}

int				ft_fractol_pthread(t_setup *setup, size_t frac, \
		void *(*f)(void *))
{
	int			err;
	size_t		i;
	size_t		inc;

	i = 0;
	inc = setup->height / NUM_THREAD;
	while (i < NUM_THREAD)
	{
		ft_fractol_cpy(setup, frac, i);
		setup[i + 1].fract[frac]->pos.y = inc * i;
		setup[i + 1].fract[frac]->height_max = inc * (i + 1);
		i++;
	}
	err = ft_pthread_process(setup, f);
	return (err);
}
