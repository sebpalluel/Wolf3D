/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:28:52 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/23 15:33:46 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static void		ft_check_if_all_one(t_setup *setup, int height)
{
	int			width;
	size_t		allone;

	width = -1;
	allone = 1;
	while (++width < M_WIDTH && allone)
		if (MAP->tmp_map[height][width] != 1)
			allone = 0;
	if (allone)
	{
		width = ft_random(1, M_WIDTH - 2, 1);
		MAP->tmp_map[height][width] = 0;
		MAP->map_str[height][width * 2] = '0';
	}
}

static void		ft_random_map(t_setup *setup)
{
	int			width[2];
	int			height;
	int			rand_num;

	height = -1;
	while (++height < M_HEIGHT)
	{
		width[0] = -1;
		width[1] = 0;
		while (++width[0] < M_WIDTH)
		{
			if ((height == 0 || height == M_HEIGHT - 1) ||\
					(width[0] == 0 || width[0] == M_WIDTH - 1))
				rand_num = 1;
			else
				rand_num = ft_random(0, MAX_ELEM, 1);
			MAP->tmp_map[height][width[0]] = (size_t)rand_num;
			MAP->map_str[height][width[1]] = *ft_itoa(rand_num);
			width[1]++;
			MAP->map_str[height][width[1]] = ' ';
			width[1]++;
		}
		if (height > 0 && (height < M_HEIGHT - 2))
			ft_check_if_all_one(setup, height);
		MAP->map_str[height][width[1]] = '\n';
	}
}

size_t			ft_generate_map(t_setup *setup)
{
	MAP->map_str = ft_tabnewstr(M_WIDTH * 2 + 1, M_HEIGHT);
	MAP->tmp_map = ft_tabnewsize_t(M_WIDTH, M_HEIGHT);
	if (&MAP->tmp_map[0] != NULL && &MAP->tmp_map[0][0] != NULL)
		ft_random_map(setup);
	PATH.pos.x = ft_random(1, M_WIDTH - 2, 1);
	PATH.pos.y = 1;
	while (ft_path_maker(setup) != OK)
		;
	//ft_convertmap_to_str(setup);
	printf("print array int :\n");
	ft_printsize_tarray(MAP->tmp_map, M_WIDTH, M_HEIGHT);
	SETUP.mode = STATE_SAVE;
	return (OK);
}
