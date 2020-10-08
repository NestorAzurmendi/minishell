/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/10/08 17:37:46 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_path(t_tab *t, char **env)
{
	int		i;
	int		j;
	char	*aux;
	char	*tmp;

	i = 0;

	//exit q hay q gestionar con errno
	while(t->path[i])
	{
		if (t->tokens[0] == NULL)
			break ;
		else
		{
			aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
			tmp = aux;
			j = execve(tmp, t->tokens, env);
			//if (j < 0)
				//printf("%s\n", strerror(errno));
			free(aux);
			i++;
		}
	}
}

void	read_path(t_tab *t, char **env)
{
	int		i;
	char *test;

	i = 0;
	while (env[i])
	{
		//t->our_env[i] = ft_strdup(env[i]);
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			t->path = ft_split(&env[i][5], ':');
		i++;
	}
}
