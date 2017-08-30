/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 17:20:12 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/30 21:19:38 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

size_t	ft_open_map(t_setup *setup)
{
	//int	ret_gnl;
	int height;
	char **tmp;
	char *path;
	//char *name;
	//char *path;

	height = -1;
	tmp = ft_strsplit(SETUP.args[1], '/');
	FD->path = ft_straddchar(tmp[0], '/');
	FD->name = tmp[1];
	printf("path %s, name %s\n", FD->path, FD->name);
	//name = ft_strdup(SETUP.args[0]);
	//FD->name = ft_strdup(ft_strrchr(name, '/'));
	//path = ft_strdup(SETUP.args[0]);
	if (ft_open(FD, O_RDONLY, O_APPEND) != OK)
		return (ERROR);
	//MAP->map_str = (char**)malloc(sizeof(char*) * M_MAX_HEIGHT);
	//while ((ret_gnl = get_next_line(FD->fd, &MAP->map_str[height++])))
	//	if (height > M_MAX_HEIGHT)
	//		return (ERROR);
	//MAP->map_str[height] = NULL;
	return (OK);
}
