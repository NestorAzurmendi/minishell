/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:03:57 by emartin-          #+#    #+#             */
/*   Updated: 2020/03/03 19:34:30 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		x;

	x = 0;
	while (src[x] != '\0' && x < n)
	{
		dest[x] = src[x];
		x++;
	}
	while (x < n)
	{
		dest[x] = '\0';
		x++;
	}
	return (dest);
}

char			*ft_strtrim(char *s1, char *set)
{
	char				*s2;
	unsigned int		a;
	unsigned int		b;

	a = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[a]) && s1[a] != '\0')
		a++;
	b = ft_strlen(s1) - a;
	if (b)
	{
		while (ft_strchr(set, s1[b + a - 1]) && a < b - 1)
			b--;
	}
	if (!(s2 = (char *)malloc(sizeof(char) * b + 1)))
		return (0);
	ft_strncpy(s2, &((char *)s1)[a], b);
	s2[b] = 0;
	return (s2);
}
