/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:29:38 by psebasti          #+#    #+#             */
/*   Updated: 2016/11/18 22:17:05 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

size_t		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]) && (i < n))
	{
		if (((unsigned const char *)s1)[i] != ((unsigned const char *)s2)[i])
			return (((unsigned const char *)s1)[i] - \
						((unsigned const char *)s2)[i]);
			i++;
	}
	return (0);
}
