/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:20:12 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/31 19:48:22 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	ft_args_to_fd(t_setup *setup)
{
	char		**tmp;

	if (!(tmp = ft_strsplit(SETUP.args[1], '/')))
		return (ERROR);
	FD->path = ft_straddchar(tmp[0], '/');
	FD->name = ft_strdup(tmp[1]);
	if (FD->path == NULL || FD->name == NULL)
		return (ERROR);
	ft_tabfree((void **)tmp);
	return (OK);
}

static size_t	ft_parse_row(t_setup *setup, char *map_str, int line)
{
	int			row;
	int			row2;

	row = -1;
	row2 = -1;
	while (++row < M_WIDTH * 2 && ++row2 < M_WIDTH)
	{
		map_str[0] = MAP->map_str[line][row];
		if (!(map_str[0] >= '0' && map_str[0] <= *ft_itoa(MAX_ELEM)) \
				|| MAP->map_str[line][row + 1] != ' ')
			return (ERROR);
		MAP->tmp_map[line][row2] = ft_atoi(map_str);
		row++;
	}
	return (OK);
}

static size_t	ft_parse_map(t_setup *setup)
{
	int			line;
	char		*map_str;

	line = -1;
	map_str = ft_strnew(1);
	if (M_WIDTH < M_MIN_SIZE || M_WIDTH > M_MAX_SIZE ||\
			M_HEIGHT < M_MIN_SIZE || M_HEIGHT > M_MAX_SIZE)
		return (ERROR);
	if (!(MAP->tmp_map = ft_tabnewsize_t(M_WIDTH, M_HEIGHT)))
		return (ERROR);
	while (++line < M_HEIGHT)
		if (ft_parse_row(setup, map_str, line) == ERROR)
			return (ERROR);
	ft_printsize_tarray(MAP->tmp_map, M_WIDTH, M_HEIGHT);
	ft_printstrarray(MAP->map_str);
	free (map_str);
	return (OK);
}

size_t			ft_open_map(t_setup *setup)
{
	int			ret_gnl;
	int 		height;

	height = -1;
	ft_args_to_fd(setup);
	if (ft_open(FD, O_RDONLY, O_APPEND) != OK)
		return (ERROR);
	MAP->map_str = (char**)malloc(sizeof(char*) * M_MAX_SIZE);
	while ((ret_gnl = get_next_line(FD->fd, &MAP->map_str[++height])))
	{
		if (height == 0)
			M_WIDTH = ft_strlen(MAP->map_str[0]) / 2;
		if (M_WIDTH != (ft_strlen(MAP->map_str[height]) / 2) ||\
				height > M_MAX_SIZE || ret_gnl == READ_ERR)
			return (ERROR);
	}
	MAP->map_str[height] = NULL;
	M_HEIGHT = height;
	SETUP.mode = STATE_RUN;
	return (ft_parse_map(setup));
}
