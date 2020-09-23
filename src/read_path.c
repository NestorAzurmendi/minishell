/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emartin- <emartin-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 18:04:38 by emartin-          #+#    #+#             */
/*   Updated: 2020/09/23 19:41:17 by emartin-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		check_path(t_tab *t)
{
	int		i;
	int		j;
	char	*aux;
	char	*tmp;

	i = 0;
	
	if(t->tokens == NULL)
		ft_putstr_fd("ERROR tokens\n", 1);
	//exit q hay q gestionar con errno
	while(t->path[i])
	{	
		aux = ft_strjoin_sl(t->path[i], t->tokens[0]);
		tmp = aux;
		//printf("valor de aux=    %s\n", aux);
		//printf("valor de tokens=    %s\n", t->tokens[0]);
		j = execve(tmp, t->tokens, t->our_env);
		if (j < 0)
			//printf("%s\n", strerror(errno));
		i++;
	}
}

void	read_path(t_tab *t, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		t->our_env[i] = ft_strdup(env[i]);
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			t->path = ft_split(&env[i][5], ':');
		i++;
	}
}