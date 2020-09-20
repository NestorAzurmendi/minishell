/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 15:44:11 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/19 18:09:41 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(unsigned int i)
{
	unsigned int		z;

	z = 1;
	while (i >= 10)
	{
		i = i / 10;
		z++;
	}
	return (z);
}

char			*ft_itoa(int n)
{
	unsigned int		i;
	unsigned int		j;
	unsigned int		z;
	char				*str;

	if (n < 0)
		i = (unsigned int)(n * -1);
	else
		i = (unsigned int)n;
	z = ft_size(i);
	if (!(str = (char*)malloc(sizeof(char) * z + 1 + (n < 0 ? 1 : 0))))
		return (0);
	if (n < 0 && (str[0] = '-'))
		z++;
	j = z - 1;
	while (i >= 10)
	{
		str[j--] = (char)(i % 10 + '0');
		i /= 10;
	}
	str[j] = (char)(i % 10 + '0');
	str[z] = 0;
	return (str);
}
