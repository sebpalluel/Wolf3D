/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:18:11 by psebasti          #+#    #+#             */
/*   Updated: 2016/11/22 18:40:14 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memdup(const void *mem, size_t size)
{
	void	*out;

	out = (void*)malloc(sizeof(size_t) * size);
	if (out != NULL)
		ft_memcpy(out, mem, size);
	return (out);
}
