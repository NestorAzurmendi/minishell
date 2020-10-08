/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 19:29:33 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/08 19:33:47 by emartin-         ###   ########.fr       */
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


static int			ft_words(char const *s, char c)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (s[i] != 0)
	{
		if (s[i] == c && s[i] != 0)
		{
			w++;
			while (s[i] == c && s[i] != 0)
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
	while (s[i] != 0 && s[i] == c)
	{
		i++;
		++l;
	}
	printf("letters  : %d\n", l);
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
		if (s[i] == c && s[i] != 0)
		{
			l = 0;
			if (!(str[w] = (char*)malloc(sizeof(char) *
			(ft_letters(s, c) + 1))))
				return (NULL);
			printf("imm in split\n");
			printf("s[i]   : %c\n", s[i]);
			while (s[i] != c && s[i] != 0)
			{
				str[w][l++] = s[i++];
				printf("str   : %s\n", str[w]);
			}
			str[w][l] = '\0';
			w++;
		}
		else
			i++;
	}
	str[w] = NULL;
	return (str);
}

char				**ft_split_com(char const *s, char c)
{
	char	**str;
	int		x;

	if (!s)
		return (NULL);
	x = ft_words(s, c);
	printf("words   : %d\n", x);
	if (!(str = (char**)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	return (prinsplit(s, c, str, x));
}
