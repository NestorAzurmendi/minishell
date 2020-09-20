/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 12:16:24 by emartin-          #+#    #+#             */
/*   Updated: 2020/05/21 11:36:35 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"


char	*ft_strjoin(char const *s1, char const *s2)
{
	int				x;
	char			*two;
	int				i;
	int				j;

	if (!s1 || !s2)
		return (0);
	x = ft_strlen(s1) + ft_strlen(s2);
	if (!(two = (char *)malloc((x + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		two[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		two[i] = s2[j];
		i++;
		j++;
	}
	two[i] = '\0';
	return (two);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*d;
	size_t		i;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (0);
	i = 0;
	while (i < len)
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

