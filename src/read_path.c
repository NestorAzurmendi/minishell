/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/09/22 18:32:07 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_path(t_tab *t)
{
	int		i;

	i = 0;
	
	while(t->path[i] != NULL)
	{	
		t->join =  ft_strjoin(t->path[i], t->argv[0]);
		printf("join : %s\n", t->path[i]);
		i++;
	}
}

void	read_path(t_tab *t, char **env)
{
	int		i;

	i = 0;
	t->our_env = env;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			t->path = ft_split(&env[i][5], ':');
		i++;
	}
}