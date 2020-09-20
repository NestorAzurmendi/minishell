/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:11:43 by emartin-          #+#    #+#             */
/*   Updated: 2019/11/12 19:08:45 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*big;
	char	*small;
	size_t	i;
	size_t	j;

	big = (char *)haystack;
	small = (char *)needle;
	i = 0;
	if (small[0] == 0)
		return (big);
	while (big[i] != 0 && i < len)
	{
		j = 0;
		if (big[i] == small[j])
		{
			while ((small[j] == big[i + j]) && (i + j < len))
			{
				j++;
				if (small[j] == 0)
					return (&((char *)haystack)[i]);
			}
		}
		i++;
	}
	return (0);
}
