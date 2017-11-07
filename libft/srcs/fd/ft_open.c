/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 20:33:45 by psebasti          #+#    #+#             */
/*   Updated: 2017/11/07 10:58:12 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_open(t_fd *fd, int flags, int rights)
{
	char	*tmp;

	if (fd->path == NULL && fd->name == NULL)
	{
		fd->fd = -1;
		return (ERROR);
	}
	tmp = ft_strjoin(fd->path, fd->name);
	if (tmp == NULL || (fd->fd = open(tmp, flags, rights)) <= 0)
	{
		free(tmp);
		return (ERROR);
	}
	free(tmp);
	return (OK);
}
