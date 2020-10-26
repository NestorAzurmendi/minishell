/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hellnhell <hellnhell@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 11:22:42 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/26 12:48:55 by hellnhell        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	x;
	int	neg;

	neg = 1;
	x = 0;
	while (*str && (*str == '\t' || *str == '\n' || *str == '\v' ||
	*str == '\f' || *str == ' ' || *str == '\r'))
		++str;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		++str;
	while (*str && *str >= '0' && *str <= '9')
	{
		x = x * 10 + (*str - 48);
		++str;
	}
	return (x * neg);
}
