/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 18:32:43 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/13 19:43:47 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int			ft_words(char const *s, char c)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			w++;
			while (s[i] != c && s[i] != 0)
				i++;
		}
		else
			i++;
	}
	return (w);
}

static int			ft_letters(const char *s, char c)
{
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[i] != 0 && s[i] != c)
	{
		i++;
		l++;
	}
	return (l);
}

static char			**prinsplit(char const *s, char c, char **str, int x)
{
	int		l;
	int		i;
	int		w;

	i = 0;
	w = 0;
	while (s[i] != 0 && w < x)
	{
		if (s[i] != c && s[i] != 0)
		{
			l = 0;
			if (!(str[w] = (char*)malloc(sizeof(char) *
			(ft_letters(s, c) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != 0)
				str[w][l++] = s[i++];
			str[w][l] = '\0';
			w++;
		}
		else
			i++;
	}
	str[w] = NULL;
	return (str);
}

char				**ft_split(char const *s, char c)
{
	char	**str;
	int		x;

	if (!s)
		return (NULL);
	x = ft_words(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	return (prinsplit(s, c, str, x));
}
