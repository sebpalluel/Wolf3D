/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:20:12 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/16 13:45:29 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

static size_t	ft_args_to_fd(t_setup *setup)
{
	char		**tmp;

	if (!(tmp = ft_strsplit(SETUP.args[1], '/')))
		return (ERROR);
	if (tmp[1] != NULL)
	{
		FD->path = ft_straddchar(tmp[0], '/');
		FD->name = ft_strdup(tmp[1]);
	}
	else
	{
		FD->path = ft_strdup("./");
		FD->name = ft_strdup(tmp[0]);
	}
	if (FD->path == NULL || FD->name == NULL)
		return (ERROR);
	ft_tabfree((void **)tmp);
	return (OK);
}

static size_t	ft_parse_row(t_setup *setup, char *map_str, int line)
{
	int			row;
	int			row2;
	char		*max_elem;

	row = -1;
	row2 = -1;
	max_elem = ft_itoa(MAX_ELEM);
	while (++row < M_WIDTH * 2 && ++row2 < M_WIDTH)
	{
		map_str[0] = MAP->map_str[line][row];
		if (!(map_str[0] >= '0' && map_str[0] <= *max_elem) \
				|| MAP->map_str[line][row + 1] != ' ')
			return (ERROR);
		MAP->map[line][row2] = ft_atoi(map_str);
		if (MAP->map[line][row2] == PATH_)
			MAP->has_path = 1;
		row++;
	}
	free(max_elem);
	return (OK);
}

static size_t	ft_parse_map(t_setup *setup)
{
	int			line;
	char		*map_str;

	line = -1;
	map_str = ft_strnew(1);
	if (M_WIDTH > M_MAX_SIZE || M_HEIGHT < M_MIN_SIZE || M_HEIGHT > M_MAX_SIZE)
		return (setup->error = MAP_ERROR);
	if (!(MAP->map = ft_tabnewsize_t(M_WIDTH, M_HEIGHT)))
		return (ERROR);
	while (++line < M_HEIGHT)
		if (ft_parse_row(setup, map_str, line) == ERROR)
			return (setup->error = MAP_ERROR);
	free(map_str);
	return (OK);
}

static size_t	ft_check_digit_or_space(char *str)
{
	int			c;
	int			len;

	c = -1;
	len = ft_strlen(str);
	while (++c < len)
		if (str[c] != ' ' && str[c] != '0' && str[c] != '1' && str[c] != '2')
			return (ERROR);
	if (len < M_MIN_SIZE * 2)
		return (ERROR);
	return (OK);
}

size_t			ft_open_map(t_setup *setup)
{
	int			ret_gnl;
	int			height;

	height = -1;
	ft_args_to_fd(setup);
	if (ft_open(FD, O_RDONLY, O_APPEND) != OK || \
			!(MAP->map_str = (char**)malloc(sizeof(char*) * M_MAX_SIZE)))
		return (setup->error = FILE_ERROR);
	while ((ret_gnl = get_next_line(FD->fd, &MAP->map_str[++height])))
	{
		if (height == 0)
			M_WIDTH = ft_strlen(MAP->map_str[0]) / 2;
		if (ft_check_digit_or_space(MAP->map_str[height]) != OK ||\
				M_WIDTH != (ft_strlen(MAP->map_str[height]) / 2) ||\
				height > M_MAX_SIZE || ret_gnl == READ_ERR)
		{
			MAP->map_str[height] = NULL;
			return (setup->error = MAP_ERROR);
		}
	}
	MAP->map_str[height] = NULL;
	M_HEIGHT = height;
	SETUP.mode = STATE_DRAW;
	return (ft_parse_map(setup));
}
