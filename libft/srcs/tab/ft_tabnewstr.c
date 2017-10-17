/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnewstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 20:20:56 by psebasti          #+#    #+#             */
/*   Updated: 2017/08/22 18:21:12 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabnewstr(size_t width, size_t height)
{
	size_t	i;
	char	**tab;

	i = 0;
	tab = (char **)ft_memalloc(sizeof(char *) * (height + 1));
	while (tab && i < height)
	{
		tab[i] = (char *)ft_memalloc(sizeof(char) * width + 1);
		tab[i][width] = '\0';
		i++;
	}
	tab[height] = NULL;
	return (tab);
}
