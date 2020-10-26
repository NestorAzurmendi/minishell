/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:29:33 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/23 19:31:16 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char			*ft_strjoin_sl(const char *s1, const char *s2)
{
	int		pos;
	char	*dest;

	if (!(dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	pos = 0;
	while (*s1)
		dest[pos++] = *s1++;
	dest[pos++] = '/';
	while (*s2)
		dest[pos++] = *s2++;
	dest[pos] = '\0';
	return (dest);
}
