/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psebasti <sebpalluel@free.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 18:53:11 by psebasti          #+#    #+#             */
/*   Updated: 2017/10/13 14:35:10 by psebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nbr)
{
	int	ret;

	ret = (nbr == 0) ? 1 : 0;
	if (ret)
		return (ret);
	if (nbr < 0)
	{
		nbr = abs(nbr);
		ret++;
	}
	while (nbr != 0)
	{
		nbr /= 10;
		ret++;
	}
	return (ret);
}
