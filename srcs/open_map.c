/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:20:12 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/31 17:39:48 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	ft_argstofd(t_setup *setup)
{
	char **tmp;

	if (!(tmp = ft_strsplit(SETUP.args[1], '/')))
		return (ERROR);
	FD->path = ft_straddchar(tmp[0], '/');
	FD->name = ft_strdup(tmp[1]);
	if (FD->path == NULL || FD->name == NULL)
		return (ERROR);
	ft_tabfree((void **)tmp);
	return (OK);
}

size_t	ft_open_map(t_setup *setup)
{
	int	ret_gnl;
	int height;

	height = -1;
	ft_argstofd(setup);
	if (ft_open(FD, O_RDONLY, O_APPEND) != OK)
		return (ERROR);
	MAP->map_str = (char**)malloc(sizeof(char*) * M_MAX_SIZE);
	while ((ret_gnl = get_next_line(FD->fd, &MAP->map_str[++height])))
		if (height > M_MAX_SIZE || ret_gnl == READ_ERR)
			return (ERROR);
	MAP->map_str[height] = NULL;
	M_WIDTH = ft_strlen(MAP->map_str[height - 1]) / 2;
	M_HEIGHT = height;
	if (M_WIDTH < M_MIN_SIZE || M_WIDTH > M_MAX_SIZE ||\
			M_HEIGHT < M_MIN_SIZE || M_HEIGHT > M_MAX_SIZE)
			return (ERROR);
	SETUP.mode = STATE_RUN;
	return (OK);
}
