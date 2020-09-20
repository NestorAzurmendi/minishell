/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:13:02 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/12 18:21:47 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*aux1;
	unsigned char	*aux2;
	int				x;
	size_t			i;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	i = 0;
	x = 0;
	while (i < n)
	{
		if (aux1[i] == aux2[i])
			i++;
		else
		{
			x = aux1[i] - aux2[i];
			return (x);
		}
	}
	return (0);
}
