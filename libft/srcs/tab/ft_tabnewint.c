/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnewint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 17:23:25 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/04 17:24:21 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			**ft_tabnewint(size_t width, size_t height)
{
	size_t	i;
	int		**tab;

	i = 0;
	tab = (int **)ft_memalloc(sizeof(int *) * (height + 1));
	while (tab && i < height)
	{
		tab[i] = (int *)ft_memalloc(sizeof(int) * width);
		i++;
	}
	tab[height] = NULL;
	return (tab);
}
