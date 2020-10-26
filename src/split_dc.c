/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:17:10 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/20 20:02:03 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int			ft_words(char const *s, char c, t_tab *t)
{
	int		w;
	int		i;

	i = 0;
	w = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			if (s[i] != 39)
			{
				w++;	
				while (s[i] != c && s[i] != 0)
				{
					if (s[i] == 39)
						break ;
					i++;	
				}
			}
			else
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

static char			**prinsplit(char const *s, char c, char **str, int x, t_tab *t)
{
	int		l;
	int		i;
	int		j;
	int		w;
	int		k;
	unsigned int start;
	size_t len;

	i = 0;
	w = 0;
	start = 0;


	while (s[i] != 0 && w < x)
	{
		if (s[i] != c && s[i] != 0)
		{
			l = 0;
			if (!(str[w] = (char*)malloc(sizeof(char) *
			(ft_letters(s, c) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != 0)
			{
				len = 0;
				j = 0;
				if (s[i] == 39)
				{
					i++;
					start = i;
					while(s[i] != 39 && s[i]!= 0)
					{
						i++;
						j++;
					}	
					len += j;
					str[w] = ft_substr(s, start, len);
					i++;
					break ;
				}
				else	
				{
					str[w][l++] = s[i++];
					str[w][l] = '\0';
				}	
			}
			w++;
		}
		else
			i++;
	}
	str[w] = NULL;
	return (str);
}

char				**ft_split_com(char const *s, char c, t_tab *t)
{
	char	**str;
	int		x;

	if (!s)
		return (NULL);
	x = ft_words(s, c, t);
	if (!(str = (char**)malloc(sizeof(char*) * (x + 1))))
		return (NULL);
	return (prinsplit(s, c, str, x, t));
}
