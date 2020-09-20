/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:54:36 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/14 18:34:06 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*dest;
	const unsigned char	*sour;

	dest = (unsigned char*)dst;
	sour = (unsigned char*)src;
	i = 0;
	if (dest == sour)
		return (dst);
	if (sour < dest)
	{
		while (i++ < len)
			dest[len - i] = sour[len - i];
	}
	else
	{
		i = 0;
		while (len-- > 0)
		{
			dest[i] = sour[i];
			i++;
		}
	}
	return (dst);
}
