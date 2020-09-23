/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 18:37:34 by emartin-          #+#    #+#             */
/*   Updated: 2020/09/23 19:44:05 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "minishell.h"

char	*ft_strtok(char *str, char *sepa)
{
	static char	*stock = NULL;
	char		*ptr;
	int			i;
	int			j;
	int			len;

	i = 0;
	ptr = NULL;
	len = ft_strlen(sepa);
	if (str != NULL)
		stock = ft_strdup(str);
	while (*stock != '\0' && i <= 1)
	{
		if (i == 0)
		{
			j = 0;
			while(j < len)
			{
				if(*stock != sepa[j])
				{
					i = 1;
					ptr = stock;
					break;
				}
				j++;
			}
		}
		if (i == 1)
		{
			j = 0;
			while(j < len)
			{
				if(*stock == sepa[j])
				{
					*stock = '\0';
					i = 27;
					printf("hola\n");
					break;
				}
				j++;
			}
		}
		stock++;
	}
	j = 0;
	while(j < len)
	{
		if(*stock == sepa[j])
		{
			j = -1;
			stock++;
		}
		j++;
	}
	return (ptr);
}

void *ft_realloc(void *ptr, size_t originalsize, size_t newsize)
{
	void *newptr;

	if (newsize == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (!ptr)
		return (malloc(newsize));
	else if (newsize <= originalsize)
		return (ptr);
	else
	{
		newptr = malloc(newsize);
		if(newptr)
		{
			ft_memcpy(newptr, ptr, originalsize);
			free(ptr);
		}
		return(newptr);
	}
}

char	**split_line(char *line)
{
	char	**tokens;
	char	*token;
	char	*sp;
	int		position;
	int		buffsize;

	buffsize = 16;
	sp = NULL;
	(void)sp;
	position = 0;
	if (!(tokens = malloc(buffsize)))
	{
		ft_putstr_fd("Error malloc\n", 1);
		return(0);
	}
	token = ft_strtok(line, " \n\t\n\a");
	while (token)
	{
		tokens[position] = token;
		position++;
		if (position >= buffsize){
			buffsize += 16;
			tokens = ft_realloc(tokens, buffsize - 16, buffsize);
			if (!tokens)
			{
				ft_putstr_fd("Error realloc tokens", 1);
			}
		}
		token = ft_strtok(NULL, " \n\t\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}