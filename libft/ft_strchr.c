/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:25:57 by emartin-          #+#    #+#             */
/*   Updated: 2020/03/04 17:25:57 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char			*ft_strchr(char *s, int c)
{
	unsigned int		pos;

	if (!s || !c)
		return (NULL);
	pos = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (&s[pos]);
		pos++;
	}
	return (NULL);
}