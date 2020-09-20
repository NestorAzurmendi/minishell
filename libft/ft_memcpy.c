/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 10:29:07 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/15 14:13:40 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	size_t			i;

	aux1 = (unsigned char *)src;
	aux2 = (unsigned char *)dst;
	if (dst == src || !n)
		return (dst);
	i = 0;
	while (i < n)
	{
		aux2[i] = aux1[i];
		i++;
	}
	return (dst);
}
