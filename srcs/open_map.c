/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:20:12 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/30 22:50:45 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

size_t	ft_open_map(t_setup *setup)
{
	int	ret_gnl;
	int height;
	char **tmp;

	height = -1;
	if (!(tmp = ft_strsplit(SETUP.args[1], '/')))
		return (ERROR);
	FD->path = ft_straddchar(tmp[0], '/');
	FD->name = ft_strdup(tmp[1]);
	if (FD->path == NULL || FD->name == NULL)
		return (ERROR);
	ft_tabfree((void **)tmp);
	if (ft_open(FD, O_RDONLY, O_APPEND) != OK)
		return (ERROR);
	MAP->map_str = (char**)malloc(sizeof(char*) * M_MAX_HEIGHT);
	while ((ret_gnl = get_next_line(FD->fd, &MAP->map_str[++height])))
	{
		printf("ret_gnl %d\n", ret_gnl);
		if (height > M_MAX_HEIGHT)
			return (ERROR);
		printf("height %d\n", height);
	}
	MAP->map_str[height] = NULL;
	M_WIDTH = ft_strlen(MAP->map_str[height - 1]);
	M_HEIGHT = height;
	printf("M_WIDTH %d, M_HEIGHT %d", M_WIDTH, M_HEIGHT);
	SETUP.mode = STATE_RUN;
	return (OK);
}
