/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 18:27:27 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/05 18:28:58 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libc.h"


int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (!s1[i]|| !s2[i])
		return(0);
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}