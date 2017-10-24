/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 21:04:34 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/24 19:38:55 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_straddchar(char *src, char c)
{
	char	*dest;
	size_t	length;

	dest = NULL;
	if (src)
	{
		length = ft_strlen(src);
		if (!(dest = ft_strnew(length + 1)))
			return (NULL);
		ft_memcpy(dest, src, length);
		dest[length] = c;
		dest[length + 1] = '\0';
	}
	return (dest);
}
